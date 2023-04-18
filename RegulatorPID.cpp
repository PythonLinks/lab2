#include "RegulatorPID.h"

using namespace std;







double RegulatorPID::symuluj(double  u){
       double result = m_gain * u +
	               m_integral * m_errorIntegral +
	               m_derivative * m_difference;
       m_difference = u - m_previousSignal;
       m_errorIntegral += u;
       return result;
    }

void RegulatorPID::setParameter(double  &reference, double value)
   {
      reference = (value < 0.0) ? 0.0 : value;
   }



