Adafruit_ADS1115 ads; //Sets up the Analog to Digital converter
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC); //Sets up the TFT screen

//Declaring the EMF_METER object
EMF_METER EMF (ads, tft);

double instEMF,minEMF,maxEMF;

void setup() {
  Serial.begin(115200);
  EMF.ADSsetup();
  tft.begin();
  tft.fillScreen(ILI9341_WHITE);
  tft.fillScreen(ILI9341_BLACK);
}

void loop() {
  instEMF=EMF.getEMF(EMF_METER::CHAN_ONE);
  EMF.runmaxmin();
  minEMF=EMF.getMin(EMF_METER::CHAN_ONE);
  maxEMF=EMF.getMax(EMF_METER::CHAN_ONE);
  EMF.makeGrid();
  EMF.plotData(ILI9341_RED,ILI9341_BLUE,512.0); //Graph function with parameters of two colors
  delay(10);
}
