# 1 "c:\\Users\\HELMAN\\Desktop\\29-FotoInterruptor\\FotoInterruptor.ino"
# 2 "c:\\Users\\HELMAN\\Desktop\\29-FotoInterruptor\\FotoInterruptor.ino" 2
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
volatile int CONTADOR = 0; // variable global CONTADOR
int ANTERIOR = 0; // variable para determinar si el valor de CONTADOR
                           // ha cambiado desde la ultima vez
void setup()
{
    lcd.begin(16, 2); // Inicializa el Display, 16 Com y 2 Fil
    Serial.begin(9600);
    Serial.println("Interrupciones"); // inicializacion de comunicacion serie a 9600 bps
    attachInterrupt(((2) == 2 ? 0 : ((2) == 3 ? 1 : -1)), sensor, 3); // interrupcion sobre pin digital 2
    lcd.setCursor(0, 0); // Posicion del Cursor, columna y fila.
    lcd.print("Interrupciones"); // Mensaje a Mostrar. lcd.setCursor(0,0);//Posicion del Cursor, columna y fila.
} // con rutina ISR llamada sensor

void loop()
{
    if (ANTERIOR != CONTADOR)
    { // si hubo un cambio respecto del valor anterior
        Serial.println(CONTADOR); // imprime en monitor serial el valor de CONTADOR
                                  // DISPLAY----------
        muestraLCD(CONTADOR);
        ANTERIOR = CONTADOR; // actualiza valor de ANTERIOR con nuevo valor

    } // de CONTADOR
}

void sensor()
{ // rutina ISR
    CONTADOR = CONTADOR + 1; // incrementa valor de CONTADOR en 1
}
// Funcion para Mostar en Display.
void muestraLCD(int numero)
{
    lcd.setCursor(0, 0); // Posicion del Cursor, columna y fila.
    lcd.print("Interrupciones");
    lcd.setCursor(0, 1); // Posicion del Cursor, columna y fila.
    lcd.print(numero);
    lcd.print("  Pasos.    ");
}
