#define USE_OCTOWS2811
#include<OctoWS2811.h>
#include<FastLED.h>

void all();
void rainbow();
void confetti();
void randy();
void lightning();
void lightning_rainbow();
void sinelon();
void juggle();
void bpm();
void rainbowWithGlitter();
void strobe();
void countdown();

#define NUM_LEDS_PER_STRIP 32
#define NUM_STRIPS 8

int NUM_LEDS = NUM_LEDS_PER_STRIP * NUM_STRIPS;

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

static uint8_t hue = 0;
uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current

byte typical_brightness = 20;
byte max_brightness = 255; 

typedef void (*SimplePatternList[])();
//SimplePatternList gPatterns = { rainbowWithGlitter, strobe, sinelon, bpm, juggle, confetti, randy, rainbow };
SimplePatternList gPatterns = { countdown };

void setup() {
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(typical_brightness);
}

void loop() {

  gPatterns[gCurrentPatternNumber]();
  hue++;

  LEDS.show();
  
  EVERY_N_MILLISECONDS( 20 ) { hue++; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS( 20 ) { nextPattern(); } // change patterns periodically
}

//all
//helper fucntion, sets entire ring to provided color in one frame.
void all(CRGB all_c){
  for(int i=0;i<NUM_LEDS;i++)
  {
    leds[i] = all_c;
  }
}

void countdown()
{
  //super ugly brute force countdown, just in case we don't get something better going.
  int t_minus[15] = {6,7,8,9,10,40,72,104,136,168,200,108,109,110,111};
  int ten[] = {21,53,85,117,149,181,213,23,24,25,26,55,58,87,90,119,122,151,154,183,186,215,216,217,218}; 
  int zero[] = {18,19,20,21,50,53,82,85,114,117,146,149,178,181,210,211,212,213};
  int nine[] = {23,24,25,26,55,58,87,90,119,120,121,122,154,186,218};
  int eight[] = {23,24,25,26,55,58,87,90,119,120,121,122,151,154,186,218,183,215,216,217};
  int seven[] = {23,24,25,26,58,90,122,154,186,218};
  int six[] = {23,24,25,26,55,87,119,120,121,122,151,154,186,218,183,215,216,217};
  int five[] = {23,24,25,26,55,87,119,120,121,122,154,186,218,215,216,217};
  int four[] =  {23,26,55,58,87,90,119,120,121,122,154,186,218};
  int three[] = {23,24,25,26,58,90,119,120,121,122,154,186,218,215,216,217};
  int two[] = {23,24,25,26,58,90,119,120,121,122,151,218,120,121,183,215,216,217};
  int one[] = {26,58,90,122,154,186,218};    
  int zero_two[] = {23,24,25,26,55,58,87,90,119,122,151,154,186,218,183,215,216,217};  
  
  all(0);

  //10
  for(int i=0;i<ARRAY_SIZE(t_minus);i++)
  {
    leds[t_minus[i]] = CRGB(255,0,0);
  }

  for(int i=0;i<ARRAY_SIZE(ten);i++)
  {
    leds[ten[i]] = CRGB(255,0,0);
  }

  FastLED.show();
  delay(1000);

  //9

    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(nine);i++)
    {
      leds[nine[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);
 //8
    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(eight);i++)
    {
      leds[eight[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);
        //7
    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(seven);i++)
    {
      leds[seven[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);        

    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(six);i++)
    {
      leds[six[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);
      
          all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(five);i++)
    {
      leds[five[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);

    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(four);i++)
    {
      leds[four[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);    

        all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(three);i++)
    {
      leds[three[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);

    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(two);i++)
    {
      leds[two[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);    

    all(0);
      
    for(int i=0;i<ARRAY_SIZE(t_minus);i++)
    {
      leds[t_minus[i]] = CRGB(255,0,0);
    }
  
    for(int i=0;i<ARRAY_SIZE(zero);i++)
    {
      leds[zero[i]] = CRGB(255,0,0);
    }  
  
    for(int i=0;i<ARRAY_SIZE(one);i++)
    {
      leds[one[i]] = CRGB(255,0,0);
    }
  
    FastLED.show();
    delay(1000);    

  for(int j=0;j<30;j++){    
      all(0);
        
      for(int i=0;i<ARRAY_SIZE(t_minus);i++)
      {
        leds[t_minus[i]] = CRGB(255,0,0);
      }
    
      for(int i=0;i<ARRAY_SIZE(zero);i++)
      {
        leds[zero[i]] = CRGB(255,0,0);
      }  
    
      for(int i=0;i<ARRAY_SIZE(zero_two);i++)
      {
        leds[zero_two[i]] = CRGB(255,0,0);
      }
    
      FastLED.show();  
      delay(500);
      all(0);
      FastLED.show();
      delay(500);
  }
}

void strobe()
{
  LEDS.setBrightness(max_brightness);
  all(CRGB(255,255,255));
  LEDS.show();
  delay(hue);
  all(CRGB(0,0,0));
  LEDS.show();
  delay(hue);
  LEDS.setBrightness(typical_brightness);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13,0,NUM_LEDS);
  leds[pos] += CHSV( hue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, hue+(i*2), beat-hue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

void nextPattern()
{
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
}
void randy()
{
  for(int i = 0; i < NUM_STRIPS; i++) {
    for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {
      leds[random(NUM_LEDS)] = CHSV(random(255),random(255),random(255));
      delay(random(j));
      LEDS.show();
      fadeToBlackBy( leds, NUM_LEDS, 1);
    }    
  }  
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( hue + random8(64), 200, 255);
}



void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, hue, 7);
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}


//  Lightnings is a program that lets you make an LED strip look like a 1D cloud of lightning
//  Original by: Daniel Wilson, 2014
//  Modified by: Andrew Tuline 2015
//  Modified slightly by: Bob Eells 2016 - mostly for lightning_rainbow below

uint8_t frequency = 80;                                       // controls the interval between strikes
uint8_t flashes = 8;                                          //the upper limit of flashes per strike
unsigned int dimmer = 1;

uint8_t ledstart;                                             // Starting location of a flash
uint8_t ledlen;                                               // Length of a flash

void lightning(){
  all(CRGB::Black);
  ledstart = random8(NUM_LEDS);           // Determine starting location of flash
  ledlen = random8(NUM_LEDS-ledstart);    // Determine length of flash (not to go beyond NUM_LEDS-1)
  for (int flashCounter = 0; flashCounter < random8(3,flashes); flashCounter++) {
    if(flashCounter == 0) dimmer = 5;     // the brightness of the leader is scaled down by a factor of 5
    else dimmer = random8(1,3);           // return strokes are brighter than the leader
    fill_solid(leds+ledstart,ledlen,CHSV(255, 0, 255/dimmer));
    FastLED.show();                       // Show a section of LED's
    delay(random8(4,10));                 // each flash only lasts 4-10 milliseconds
    fill_solid(leds+ledstart,ledlen,CHSV(255,0,0));   // Clear the section of LED's
    FastLED.show();     
    if (flashCounter == 0) delay (150);   // longer delay until next flash after the leader
    delay(50+random8(100));               // shorter delay between strokes  
  } // for()
  delay(random8(frequency)*100);          // delay between strikes
}

void lightning_rainbow(){
  all(CRGB::Black);
  ledstart = random8(NUM_LEDS);           // Determine starting location of flash
  ledlen = random8(NUM_LEDS-ledstart);    // Determine length of flash (not to go beyond NUM_LEDS-1)
  for (int flashCounter = 0; flashCounter < random8(3,flashes); flashCounter++) {
    if(flashCounter == 0) dimmer = 5;     // the brightness of the leader is scaled down by a factor of 5
    else dimmer = random8(1,3);           // return strokes are brighter than the leader
    fill_solid(leds+ledstart,ledlen,CHSV(random(255), 255, 255/dimmer));
    FastLED.show();                       // Show a section of LED's
    delay(random8(3,16));                 // duration of min/max delays in ms
    fill_solid(leds+ledstart,ledlen,CHSV(random(255),255,0));   // Clear the section of LED's
    FastLED.show();     
    if (flashCounter == 0) delay (150);   // longer delay until next flash after the leader
    delay(50+random8(100));               // shorter delay between strokes  
  } // for()
  delay(random8(frequency)*100);          // delay between strikes
}

