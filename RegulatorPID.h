#ifndef  MyCLASS
#define MyCLASS

class ObiektSISO
{
public:
    virtual double symuluj(double u);
        ~ObiektSISO();
};



class RegulatorPID : public ObiektSISO
{
    public:

        RegulatorPID(double gain,
		     double integral,
		     double derivative)
{
  setParameter ( m_gain, gain);
  setParameter( m_integral, integral);
  setParameter (m_derivative, derivative);
};

RegulatorPID(double gain, double integral ) :
  RegulatorPID {gain,integral,0.0} {};
  RegulatorPID(double gain) : RegulatorPID{gain,0.0,0.0} {};


  ~RegulatorPID() {};
  virtual double symuluj(double u);
  void setParameter(double  &parameter,double value);

private:
  double m_gain;
  double m_integral;
  double m_derivative;
  double m_previousSignal;
  double  m_errorIntegral {0.0};
  double  m_difference {0.0};

};


#endif
