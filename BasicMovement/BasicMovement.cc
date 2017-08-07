'*******************************************************************************
'
'   Project name: Basic movement
'
'*******************************************************************************


#define Motor_Enable 15


'Mainprogramm
Sub main()

    Dim PWM_Counter As Integer

    Timer_T1PWMX(255,128,128,PS_8)                       'Config For Cannel A und B (Timer1)

    Port_DataDirBit(Motor_Enable,PORT_OUT)               'Port Enable Motor = Output
    Port_WriteBit(Motor_Enable,1)                        'Port = High +5V


        Timer_T1PWA(128)                                 'PWM Channel A = 50/50
        Timer_T1PWB(128)                                 'PWM Channel B = 50/50
        AbsDelay(3000)                                   'Wait 3sec


        For PWM_Counter = 128 To 255
            Timer_T1PWA(PWM_Counter)
            Timer_T1PWB(PWM_Counter)
            AbsDelay(20)
        Next
        AbsDelay(3000)

        For PWM_Counter = 255 To 128 Step -1
            Timer_T1PWA(PWM_Counter)
            Timer_T1PWB(PWM_Counter)
            AbsDelay(20)
        Next
        AbsDelay(3000)

        For PWM_Counter = 128 To 1 Step -1
            Timer_T1PWA(PWM_Counter)
            Timer_T1PWB(PWM_Counter)
            AbsDelay(20)
        Next
        AbsDelay(3000)

        For PWM_Counter = 1 To 128
            Timer_T1PWA(PWM_Counter)
            Timer_T1PWB(PWM_Counter)
            AbsDelay(20)
        Next
        AbsDelay(3000)

        Port_WriteBit(Motor_Enable,0)                    'Port = low 0V

End Sub