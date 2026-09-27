#include "cmsis_os.h"
#include "io/buzzer/buzzer.hpp"

// C板蜂鸣器: TIM4_CH3 (PB8), APB1 定时器时钟 84MHz
sp::Buzzer buzzer(&htim4, TIM_CHANNEL_3, 84e6);

extern "C" void buzzer_Task()
{
  buzzer.set(5000, 0.1);  // 5kHz 发声频率，10% 占空比

  for (int i = 0; i < 3; i++) {
    buzzer.start();
    osDelay(100);  // 响 100ms
    buzzer.stop();
    osDelay(100);  // 停 100ms
  }

  while (true) {
    osDelay(100);  // 响完三声后任务挂着，不退出
  }
}