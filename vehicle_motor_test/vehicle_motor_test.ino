
#include <Servo.h> //Servo kütüphanesi motorları sürmek için gerekli PWM frekansını  sağlıyor.
//Kütüphane mevcut değil ise https://github.com/arduino-libraries/Servo adresinden indirmeniz gerekli.

#define maxdeger 1940 //Max 2000. Escler 1000-2000 arası calisir
#define mindeger 1060 //Min 1000. Escler 1000-2000 arası calisir

MCP2515 mcp2515(8);

Servo yukselis, onsa, onso, arsa, arso;

int yuk_deger, onsa_deger, onso_deger, arsa_deger, arso_deger;

void setup() 
{
    Serial.begin(115200);
    Serial.println("Basladi.");
    SPI.begin();
    
    yukselis.attach(3, 1000, 2000);
    onsa.attach(5, 1000, 2000);
    onso.attach(6, 1000, 2000);
    arsa.attach(9, 1000, 2000);
    arso.attach(10, 1000, 2000);

    //Motorlar 1500 değerinde armlanıyor.
    yukselis.writeMicroseconds(1500);
    onsa.writeMicroseconds(1500);
    onso.writeMicroseconds(1500);
    arsa.writeMicroseconds(1500);
    arso.writeMicroseconds(1500); 
    delay(3000);
              
}

void loop()
{             //Tum motorlar sira ile calisir, yanlis pine takilan motor varsa belli olur.
              //Sırasıyla ön sağ, ön sol, arka sağ, arka sol şeklinde çalışır. Aktif etmek için // işaretini aşağıdaki satırdan silin.
              //siraylacalistir();

              //Dikkatli olun, motorlara güç vermeden önce elinizle döndürerek bir şey sıkışmadığından emin olun. 
              //Motorlar çalışırken elinizi hazne içine yaklaştırmayın.
              //Motorlar bir noktaya sabitlenmemişken elinizle tutarak çalıştırmayı denemeyin.
              //Motorlar aşağıda belirttiğiniz ms aralığında tam güç çalışır (2000=2sn).
              //Daha sonra belirttiğiniz sürenin yarısı süre kadar durarak bekler.
              //Aktif etmek için // işaretini aşağıdaki satırdan silin.
              //tamguccalistir(2000);
}
void siraylacalistir()
{
              //Hangi motor nerede diye çözmek için,
              //Motorlar Sırasıyla ön sağ, ön sol, arka sağ, arka sol şeklinde çalışacak.
              //Nihai sistemde iptal edilmesi gerekir.
              delay(5000);
              onsa.writeMicroseconds(1500);
              delay(500);
              onso.writeMicroseconds(1500);//arso
              delay(500);
              arsa.writeMicroseconds(1500);
              delay(500);
              arso.writeMicroseconds(1500);//onso
              delay(500);
              
              onsa.writeMicroseconds(1600);
              delay(1000);
              onso.writeMicroseconds(1600);//arso
              delay(1000);
              arsa.writeMicroseconds(1600);//
              delay(1000);
              arso.writeMicroseconds(1600);//önso
              delay(2000);
              onsa.writeMicroseconds(1500);
              delay(500);
              onso.writeMicroseconds(1500);
              delay(500);
              arsa.writeMicroseconds(1500);
              delay(500);
              arso.writeMicroseconds(1500);
              delay(500);
  }
void tamguccalistir(int sure)
{
              //Hangi motor nerede diye çözmek için,
              //Motorlar Sırasıyla ön sağ, ön sol, arka sağ, arka sol şeklinde çalışacak.
              //Nihai sistemde iptal edilmesi gerekir.
              delay(1000);
              onsa.writeMicroseconds(2000);
              onso.writeMicroseconds(2000);//arso
              arsa.writeMicroseconds(2000);
              arso.writeMicroseconds(2000);//onso
              delay(sure);
              
              onsa.writeMicroseconds(1500);
              onso.writeMicroseconds(1500);//arso
              arsa.writeMicroseconds(1500);//
              arso.writeMicroseconds(1500);//önso
              delay(sure/2);
  }
