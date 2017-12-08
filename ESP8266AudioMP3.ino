#include <Arduino.h>
#include "AudioGeneratorMP3a.h"
#include "AudioOutputI2SDAC.h"
#include "AudioFileSourcePROGMEM.h"
#include "samplemp3.h"

AudioFileSourcePROGMEM *in;
AudioGeneratorMP3a *mp3;
AudioOutputI2SDAC *out;

void setup()
{
  Serial.begin(115200);
  
  in = new AudioFileSourcePROGMEM(samplemp3, sizeof(samplemp3));
  mp3 = new AudioGeneratorMP3a();
  out = new AudioOutputI2SDAC();
  Serial.println("mp3 begin\n");
  mp3->begin(in, out);
}


void loop()
{
  if (mp3->isRunning()) {
    mp3->loop();
  } else {
    Serial.printf("MP3 done\n");
    delay(1000);
  }
}

