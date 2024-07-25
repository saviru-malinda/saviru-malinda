const int button_pin = 2;
const int led_pin = 9;

int button_state;

void setup()
{
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  button_state = digitalRead(button_pin);
  if (button_state == HIGH)
  {
    digitalWrite(led_pin, LOW);
  }
  else
  {
    digitalWrite(led_pin, HIGH);
  }
}