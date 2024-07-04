void basic_line_follow(){
  while (1){
    reading ();

    if(sum == 0){
      motor(0 , 0);
    }
    if(sum == 1 || sum == 2){
       if(sensor == 0b001100){
        motor(10*spl, 10*spr); Serial.print("froward");
        Serial.print(" " );
       }
       // right side 
       else if(sensor == 0b000100){
        motor(10*spl, 9*spr); Serial.print("right");
        Serial.print(" " );
       }
        else if(sensor == 0b000110){
          motor(10*spl, 6*spr); Serial.print("right");
          Serial.print(" " );
        }
         else if(sensor == 0b000010){
          motor(10*spl, 3*spr); Serial.print("right");
          Serial.print(" " );
         }
          else if(sensor == 0b000011){
            motor(10*spl, 0*spr); Serial.print("right");
            Serial.print(" " );
          }
           else if(sensor == 0b000001){
            motor(10*spl, -3*spr); Serial.print("right");
            Serial.print(" " );
           }
         // left side 
         else if(sensor == 0b001000){
          motor(9*spl, 10*spr); Serial.print("left");
          Serial.print(" " );
         }
         else if(sensor == 0b011000){
          motor(6*spl, 10*spr); Serial.print("left");
          Serial.print(" " );
         }
         else if(sensor == 0b010000){
          motor(3*spl, 10*spr); Serial.print("left");
          Serial.print(" " );
         }
         else if(sensor == 0b110000){
          motor(0*spl, 10*spr); Serial.print("left");
         Serial.print(" " );
         }
         else if(sensor == 0b100000){
          motor(-3*spl, 10*spr); Serial.print("left");
          Serial.print(" " );
         }
        
    }
  }
}
