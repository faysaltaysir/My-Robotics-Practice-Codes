// int reading;
void linefollow(){
  int pos;
  while(1){
    sensorRead(b);
    if(sum == 0) {     // sensor ==0b000000
      if (flag != 's'){
        motor (10*spl, 10*spr);
        delay(10);
        if(flag == 'l'){
          motor(-6*spl, 6*spr);
          while( s[2] == 0 || s[3] == 0) sensorRead(b); // while ( sensor != 0b001100 && sensor != 0b001000 && sensor != 0B000100) reading();
        }
        else if(flag == 'r'){
          motor(6*spl, -6*spr);
          while( s[2] == 0 || s[3] == 0) sensorRead(b);
        }
        else if(flag == 't'){
          motor(6*spl, -6*spr); //for T we can use either right or left
          while( s[2] == 0 || s[3] == 0) sensorRead(b);
        }
        flag = 's';
      }
    }
    if(sum == 1 || sum==2){

      if (sensor == 0b001100) {    // only for straight line
        if(flag == 't') flag == 's';  // s for straight line
        if(pos != 0){
          (pos == 1) ? motor(-10*spl, 10*spr) : motor(10*spl, -10*spr);
          delay(10); // it should be calibrated properly
          pos = 0;
        }
        motor(10*spl, 10*spr);
        }  // motor should be calibrated


      // right side portion
      else if (sensor == 0b000100) {
        if(flag == 't') flag == 's';
        motor(10*spl , 9*spr) ;
        pos = 1;
      }
      else if (sensor == 0b000110) {
        motor(10*spl , 6*spr) ;
        pos = 1;
      }
      else if (sensor == 0b000010) {
        motor(10*spl , 3*spr) ;
        pos = 1;
      }

      else if (sensor == 0b000011) {
        motor(10*spl , 0*spr) ;
        pos = 1;
      }
      else if (sensor == 0b000001) {
        motor(10*spl , -3*spr) ;
        pos = 1;
      }


      // left side portion
      else if (sensor == 0b100000) {
        if(flag == 't') flag == 's';
        motor(-3*spl , 10*spr) ;
        pos = -1;
      }
      else if (sensor == 0b110000) {
        motor(0*spl , 10*spr) ;
        pos = -1;
      }
      else if (sensor == 0b010000) {
        motor(3*spl , 10*spr) ;
        pos = -1;
      }
      else if (sensor == 0b011000) {
        motor(6*spl , 10*spr) ;
        pos = -1;
      }
      else if (sensor == 0b001000) {
        motor(9*spl , 10*spr) ;
        pos = -1;
      }

    }
    
    // sharp turn

    if((sum == 3 || sum == 4 || sum == 5) && flag != 't'){
      // triangle 

      /* triangle e error komate chaile delay komate hbe or advance coding korte hbe */

      if(sensor == 0b001101 || sensor == 0b011001 || sensor == 0b0010011) flag = 'r'; // this one is for 30 degree triangle whis is on right side 


      else if(sensor == 0b110100 || sensor == 0b110010 || sensor == 0b1001100) flag = 'l'; // this one is for 30 degree triangle whis is on left side

      // 90 degree left

      else if (sensor == 0b111100 || sensor == 0b111000 || sensor == 0b110000) flag='l';

      // 90 degree right

      else if (sensor == 0b001111 || sensor == 0b000111 || sensor == 0b000011) flag='r';


    }

    else if (sum == 6){
      delay(100);
      sensorRead(b);

      if(sum==6){
        motor(0,0);
        while(sum==6) sensorRead(b);
        delay(500);
      }
      else if(sum == 0) flag = 't';
      

    }
    


  }
}