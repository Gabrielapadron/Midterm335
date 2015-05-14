//CMPS 335
//mid335.cpp
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4
//FREQUENCY VALUE GIVEN
double fq[]={16.3516,17.3239,18.354,19.4454,20.6017,21.8268,23.1247,24.4997,25.9565,27.5,29.1352,30.8677,32.7032,34.6478,36.7081,38.8909,41.2034};
//Tolerance
const float tolerance = 0.004;
typedef enum {
	C = 1,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	END = B,
	HALF_STEPS_PER_OCTAVE = B 
} note_t;
//FREQUENCY FUNCTION
double freq(note_t note, int octave_delta);
int main(int argc, char *argv[])
{
	note_t note;
	float t=0;
        float value1;
        float diff;
	int octave_delta;

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
		return 0;
	}
	//
	note = (note_t)(toupper(argv[1][0]) - 64);
	switch(toupper(argv[1][0])) {
		case 'A': note = A; break;
		case 'B': note = B; break;
		case 'C': note = C; break;
		case 'D': note = D; break;
		case 'E': note = E; break;
		case 'F': note = F; break;
	}
	//You may call your unit test here...
        cout<<"tolerance: "<<tolerance<<endl;
	cout<<"freq function unit-test\n"<<endl;
        cout<<"note\toctive\tvalue\tdiff\n";
        cout<<"-----\t-----\t-------\t------\n";
        
         for(int i=1;i<13;i++)
         {
         note=A;
         freq(note,1);
         //value1=fq[i];
         diff=fq[i]-t;
         if(fabs(fq[i]-t)<tolerance){
          cout<<"Error at: "<<fq[i]<<endl;
          }
         }
	


	if (note > END) {
        cout<<diff; 
		return 1;
	}
	octave_delta = atoi(argv[2]);
//	cout << HALF_STEPS_PER_OCTAVE << endl;
//	cout << freq(note, octave_delta) << endl;
	return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
	double freq;
	double factor;
	double a;
	int n;
	int octave = octave_delta - F0_octave;

	a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
	n = note - F0_note;
	freq = F0 * pow(a, (double)n);
	factor = pow(2.0, (double)octave);
	freq = freq * factor;
	return freq;
}

