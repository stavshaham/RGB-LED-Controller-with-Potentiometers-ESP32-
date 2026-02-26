// GPIO Pin, make sure to connect correctly
#define RED_POT 34 // Red potentiometer connected to GPIO 34 (ADC1)
#define GREEN_POT 35 // Green potentiometer connected to GPIO 35 (ADC1)
#define BLUE_POT 36 // Blue potentiometer connected to GPIO 36 (ADC1)

#define RED_LED 21 // Red leg from LED light connected to GPIO 21 (PWM Pin)
#define GREEN_LED 22 // Green leg from LED light connected to GPIO 22 (PWM Pin)
#define BLUE_LED 23 // Blue leg from LED light connected to GPIO 23 (PWM Pin)

// Smooth Values
float rSmooth = 0;
float gSmooth = 0;
float bSmooth = 0;

// These values can be changed
const float SMOOTHING = 0.08; // Higher = faster response
const float GAMMA = 2.2; // Brightness correction, do not recommend to change

void setup() {
  // Set the rate in the serial monitor to 9600 baud
  Serial.begin(9600);

  // Returning 12 bits from analog pin to allow full read (255)
  analogReadResolution(12);

  // Set rettenuation to 11db
  analogSetPinAttenuation(RED_POT, ADC_11db);
  analogSetPinAttenuation(GREEN_POT, ADC_11db);
  analogSetPinAttenuation(BLUE_POT, ADC_11db);

  // Configure PWM signals
  ledcAttach(RED_LED, 5000, 8);
  ledcAttach(GREEN_LED, 5000, 8);
  ledcAttach(BLUE_LED, 5000, 8);
}

// Gamma correction function
int gammaCorrect(float value) {
  return (int)(pow(value / 255.0, GAMMA) * 255.0 + 0.5);
}

void loop() {

  // Read the analog pin information
  int rRaw = analogRead(RED_POT);
  int gRaw = analogRead(GREEN_POT);
  int bRaw = analogRead(BLUE_POT);

  // Map to 0–255
  float r = map(rRaw, 0, 4095, 0, 255);
  float g = map(gRaw, 0, 4095, 0, 255);
  float b = map(bRaw, 0, 4095, 0, 255);

  // Smooth once (exponential moving average)
  rSmooth += (r - rSmooth) * SMOOTHING;
  gSmooth += (g - gSmooth) * SMOOTHING;
  bSmooth += (b - bSmooth) * SMOOTHING;

  // Gamma correction
  int rOut = gammaCorrect(rSmooth);
  int gOut = gammaCorrect(gSmooth);
  int bOut = gammaCorrect(bSmooth);

  // Output PWM
  ledcWrite(RED_LED, rOut);
  ledcWrite(GREEN_LED, gOut);
  ledcWrite(BLUE_LED, bOut);

  delay(10);
}