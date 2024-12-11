#include <Arduino.h>
#include <Wire.h>

#define TEMPERATURE_SENSOR 12

void read_temp(double *temperature, unsigned sample_count);

void setup()
{
  Serial.begin(115200);
  pinMode(TEMPERATURE_SENSOR, INPUT);
}

void loop()
{
  double temperature = 0.0;
  read_temp(&temperature, 1000);
  Serial.println(temperature);
}

// Read the temperature from the sensor
// Multiple samples are taken and averaged to reduce noise
void read_temp(double *temperature, unsigned sample_count)
{
  unsigned raw = 0;
  for (int i = 0; i < sample_count; i++)
  {
    raw += analogReadMilliVolts(TEMPERATURE_SENSOR);
  }
  *temperature = (double)raw / ((double)sample_count * 10.0);
}