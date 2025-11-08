// 定义外部中断引脚（以Arduino Uno为例，通常为数字引脚2）
const int interruptPin = 2;
// 定义中断服务例程
bool f = true;
void InterruptHandler() {
  double t = double(micros())/1000;
  if (f){
    Serial.print("1: ");
  }else{
    Serial.print("2: ");
  }
  Serial.println(t);
  f = !f;
}
void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  // 设置中断引脚为输入模式
  pinMode(interruptPin, INPUT);
  // 启用外部中断，下降沿触发
  Serial.println("Connnected");
  attachInterrupt(digitalPinToInterrupt(interruptPin), InterruptHandler, FALLING);
}
void loop() {
  
}