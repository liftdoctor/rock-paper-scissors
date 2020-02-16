/*
  Rock-Paper-Scissors Game v1 - 20140110
  by Mark Davidson
  tinkineering.com
 */
 
// Define all the I/O pins with names I can read and remember.
int scoreMinus4 = 2;
int scoreMinus3 = 3;
int scoreMinus2 = 4;
int scoreMinus1 = 5;
int scoreEven = 6;
int scorePlus1 = 7;
int scorePlus2 = 8;
int scorePlus3 = 9;
int scorePlus4 = 10;
int arduinoRock = 11;
int arduinoPaper = 12;
int arduinoScissors = 13;
int playerRock = A2;
int playerPaper = A1;
int playerScissors = A0;
int buttonRock = A3;
int buttonPaper = A4;
int buttonScissors = A5;

//Define some other stuff.
long randNumber = 0;
int needArduinoPlay = 0;
int needPlayerPlay = 0;
int score = 0;
int arduinoPlay = 0;
int playerPlay = 0;

// Initialize a bunch of stuff at boot up.
void setup() {
  pinMode(scoreMinus4, OUTPUT);     
  pinMode(scoreMinus3, OUTPUT);     
  pinMode(scoreMinus2, OUTPUT);     
  pinMode(scoreMinus1, OUTPUT);     
  pinMode(scoreEven, OUTPUT);     
  pinMode(scorePlus1, OUTPUT);     
  pinMode(scorePlus2, OUTPUT);     
  pinMode(scorePlus3, OUTPUT);     
  pinMode(scorePlus4, OUTPUT);     
  pinMode(arduinoRock, OUTPUT);     
  pinMode(arduinoPaper, OUTPUT);     
  pinMode(arduinoScissors, OUTPUT);     
  pinMode(playerRock, OUTPUT);     
  pinMode(playerPaper, OUTPUT);     
  pinMode(playerScissors, OUTPUT);     
  pinMode(buttonRock, INPUT);     
  pinMode(buttonPaper, INPUT);     
  pinMode(buttonScissors, INPUT);   

  randomSeed(100);  
}


void loop() {

  // Try to pick a random number and decide if the Arduino is playing Paper, Rock, or Scissors.
  if (needArduinoPlay == 0) {
    randNumber = random(300);
    
    if (randNumber < 100) {
      arduinoPlay = 1;
      needArduinoPlay = 1;
    }
    else if (randNumber < 200) {
      arduinoPlay = 2;
      needArduinoPlay = 1;
    }
    else {
      arduinoPlay = 3;
      needArduinoPlay = 1;
    }
  }
  
  // Set the Player's play of Rock, Paper, or Scissors.
  if (needPlayerPlay == 0) {
    if (digitalRead(buttonRock) == HIGH && digitalRead(buttonPaper) == LOW && digitalRead(buttonScissors) == LOW) {
      playerPlay = 1;
      needPlayerPlay = 1;
    }
    else if (digitalRead(buttonRock) == LOW && digitalRead(buttonPaper) == HIGH && digitalRead(buttonScissors) == LOW) {
      playerPlay = 2;
      needPlayerPlay = 1;
    }
    else if (digitalRead(buttonRock) == LOW && digitalRead(buttonPaper) == LOW && digitalRead(buttonScissors) == HIGH) {
      playerPlay = 3;
      needPlayerPlay = 1;
    }
  }
  
  if (arduinoPlay != 0 && playerPlay != 0) {
    
    // Decide who won and adjust the score.
    if ((arduinoPlay == 1 && playerPlay == 2) || (arduinoPlay == 2 && playerPlay == 3) || (arduinoPlay == 3 && playerPlay == 1)) {
      score = score + 1;
      needArduinoPlay = 0;
      needPlayerPlay = 0;
    }
    else if ((arduinoPlay == 1 && playerPlay == 3) || (arduinoPlay == 2 && playerPlay == 1) || (arduinoPlay == 3 && playerPlay == 2)) {
      score = score - 1;
      needArduinoPlay = 0;
      needPlayerPlay = 0;
    }
    else {
      score = score;
      needArduinoPlay = 0;
      needPlayerPlay = 0;
    }
    
    // Light all the Play LED indicators and update the scorekeeper.
    if (arduinoPlay == 1) {
      digitalWrite(arduinoRock, HIGH);
    }
    else if (arduinoPlay == 2) {
      digitalWrite(arduinoPaper, HIGH);
    }
    else if (arduinoPlay == 3) {
      digitalWrite(arduinoScissors, HIGH);
    }
    
    if (playerPlay == 1) {
      digitalWrite(playerRock, HIGH);
    }
    else if (playerPlay == 2) {
      digitalWrite(playerPaper, HIGH);
    }
    else if (playerPlay == 3) {
      digitalWrite(playerScissors, HIGH);
    }
    
    arduinoPlay = 0;
    playerPlay = 0;
    while (digitalRead(buttonRock) == HIGH || digitalRead(buttonPaper) == HIGH || digitalRead(buttonScissors) == HIGH) {
      delay(50);
    }
    
  }
  
  digitalWrite(arduinoRock, LOW);
  digitalWrite(arduinoPaper, LOW);
  digitalWrite(arduinoScissors, LOW);
  digitalWrite(playerRock, LOW);
  digitalWrite(playerPaper, LOW);
  digitalWrite(playerScissors, LOW);
  
  digitalWrite(scoreMinus4, LOW);
  digitalWrite(scoreMinus3, LOW);
  digitalWrite(scoreMinus2, LOW);
  digitalWrite(scoreMinus1, LOW);
  digitalWrite(scoreEven, LOW);
  digitalWrite(scorePlus1, LOW);
  digitalWrite(scorePlus2, LOW);
  digitalWrite(scorePlus3, LOW);
  digitalWrite(scorePlus4, LOW);
  if (score == -4) {
    digitalWrite(scoreMinus4, HIGH);
  }
  else if (score == -3) {
    digitalWrite(scoreMinus3, HIGH);
  }
  else if (score == -2) {
    digitalWrite(scoreMinus2, HIGH);
  }
  else if (score == -1) {
    digitalWrite(scoreMinus1, HIGH);
  }
  else if (score == 0) {
    digitalWrite(scoreEven, HIGH);
  }
  else if (score == 1) {
    digitalWrite(scorePlus1, HIGH);
  }
  else if (score == 2) {
    digitalWrite(scorePlus2, HIGH);
  }
  else if (score == 3) {
    digitalWrite(scorePlus3, HIGH);
  }
  else if (score == 4) {
    digitalWrite(scorePlus4, HIGH);
  }
  
  if (score == -5) {
    for (int x = 0; x < 3; x++) {
      digitalWrite(scoreMinus4, HIGH);
      digitalWrite(scoreMinus3, HIGH);
      digitalWrite(scoreMinus2, HIGH);
      digitalWrite(scoreMinus1, HIGH);
      delay(250);
      digitalWrite(scoreMinus4, LOW);
      digitalWrite(scoreMinus3, LOW);
      digitalWrite(scoreMinus2, LOW);
      digitalWrite(scoreMinus1, LOW);
      delay(250);
    }
    score = 0;
  }
  
  if (score == 5) {
    for (int x = 0; x < 3; x++) {
      digitalWrite(scorePlus4, HIGH);
      digitalWrite(scorePlus3, HIGH);
      digitalWrite(scorePlus2, HIGH);
      digitalWrite(scorePlus1, HIGH);
      delay(250);
      digitalWrite(scorePlus4, LOW);
      digitalWrite(scorePlus3, LOW);
      digitalWrite(scorePlus2, LOW);
      digitalWrite(scorePlus1, LOW);
      delay(250);
    }
    score = 0;
  }
  
}
