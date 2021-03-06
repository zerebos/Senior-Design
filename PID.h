#ifndef PID_v1_h
#define PID_v1_h
#define LIBRARY_VERSION	1.0.0

	//Constants used in some of the functions below
	#define AUTOMATIC	1
	#define MANUAL	0
	#define DIRECT  0
	#define REVERSE  1

	//commonly used functions **************************************************************************
	PID_Setup(double*, double*, double*,        // * constructor.  links the PID to the Input, Output, and 
		double, double, double, int);     //   Setpoint.  Initial tuning parameters are also set here

	void PID_SetMode(int Mode);               // * sets PID to either Manual (0) or Auto (non-0)

	bool PID_Compute();                       // * performs the PID calculation.  it should be
										  //   called every time loop() cycles. ON/OFF and
										  //   calculation frequency can be set using SetMode
										  //   SetSampleTime respectively

	void PID_SetOutputLimits(double, double); //clamps the output to a specific range. 0-255 by default, but
										  //it's likely the user will want to change this depending on
										  //the application



	//available but not commonly used functions ********************************************************
	void PID_SetTunings(double, double,       // * While most users will set the tunings once in the 
					double);         	  //   constructor, this function gives the user the option
										  //   of changing tunings during runtime for Adaptive control
	void PID_SetControllerDirection(int);	  // * Sets the Direction, or "Action" of the controller. DIRECT
										  //   means the output will increase when error is positive. REVERSE
										  //   means the opposite.  it's very unlikely that this will be needed
										  //   once it is set in the constructor.
	void PID_SetSampleTime(int);              // * sets the frequency, in Milliseconds, with which 
										  //   the PID calculation is performed.  default is 100
										  
										  
										  
	//Display functions ****************************************************************
	double PID_GetKp();						  // These functions query the pid for interal values.
	double PID_GetKi();						  //  they were created mainly for the pid front-end,
	double PID_GetKd();						  // where it's important to know what is actually 
	int PID_GetMode();						  //  inside the PID.
	int PID_GetDirection();					  //

	void PID_Initialize();

	double PID_dispKp;				// * we'll hold on to the tuning parameters in user-entered 
	double PID_dispKi;				//   format for display purposes
	double PID_dispKd;				//

	double PID_kp;                  // * (P)roportional Tuning Parameter
	double PID_ki;                  // * (I)ntegral Tuning Parameter
	double PID_kd;                  // * (D)erivative Tuning Parameter

	int PID_controllerDirection;

	double *PID_myInput;              // * Pointers to the Input, Output, and Setpoint variables
	double *PID_myOutput;             //   This creates a hard link between the variables and the 
	double *PID_mySetpoint;           //   PID, freeing the user from having to constantly tell us
								  //   what these values are.  with pointers we'll just know.
			  
	unsigned long PID_lastTime;
	double PID_ITerm, PID_lastInput;

	unsigned long PID_SampleTime;
	double PID_outMin, PID_outMax;
	bool PID_inAuto;

#endif

