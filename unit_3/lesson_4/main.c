
#define SYSCTL       0x400FE000
#define GPIOF     0x40025000
#define SYSCTL_RCGC2_R         *((volatile unsigned long *)(SYSCTL+0X108))
#define GPIO_PORTF_DATA_R      *((volatile unsigned long *)(GPIOF+0X3FC))
#define GPIO_PORTF_DIR_R       *((volatile unsigned long *)(GPIOF+0X400))
#define GPIO_PORTF_DEN_R       *((volatile unsigned long *)(GPIOF+0X51C))




int main(void)
{
  volatile unsigned long delay ;
 
  SYSCTL_RCGC2_R = 0X00000020;
   for (delay = 0; delay < 200 ; delay++);
 
   GPIO_PORTF_DIR_R |= 1<<3 ;
   GPIO_PORTF_DEN_R |= 1<<3 ;

 while(1)
   {
      GPIO_PORTF_DATA_R |=1<<3;     
      for( delay=0;delay<50000;delay++);
      
      GPIO_PORTF_DATA_R &= ~(1<<3);  
      for( delay=0;delay<50000;delay++);

   }
   return 0;
}
