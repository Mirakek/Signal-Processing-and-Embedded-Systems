float x[] = {0,0,0};
float y[] = {0,0,0};
int j = 0;

void setup() {
  Serial.begin(115200); //Baud Rate
  Serial.println("Input_Signal:,Filtered_Output_Signal:"); // Legend
}

void loop() {
  // Generating our signal that we want (or in turn use a signal reader and have data input into here)
  float t = micros()/1.0e6;
  x[0] = sin(2*PI*2*t) + 0.5*sin(2*PI*25*t); // x = input signal

  // Filtering signal with coefficients and difference equation
  float b[] = {0.00500141, 0.00500141};
  float a[] = {0.98999718};
  y[0] = a[0]*y[1] + b[0]*x[0] + b[1]*x[1];

  if(j % 3 ==0)
  {
    // Plotting data and printing
    Serial.print(2*x[0]);
    Serial.print(",");
    Serial.println(2*y[0]);
  }

  delay(1); // 1ms delay to prevent overflow
  for(int i = 1; i >= 0; i--){
    x[i+1] = x[i]; // new weights
    y[i+1] = y[i]; // new weights
  }
  
  j = j+1;
}
