#include <iostream>
#include <fstream>
#include "rrLogger.h"
#include "rrUtils.h"
#include "unit_test/UnitTest++.h"
#include "unit_test/XmlTestReporter.h"
#include "unit_test/TestReporterStdOut.h"
#include "Args.h"
#include "rrRoadRunner.h"
#include "rrGetOptions.h"

using namespace std;
using namespace rr;
using namespace UnitTest;

RoadRunner* gRR = NULL;

string gSBMLModelsPath = "";
string gCompilerPath = "";
string gSupportCodeFolder = "";

//Test suite
string gTSModelsPath 		= "r:\\SBMLTS\\cases\\semantic";
string gTSDataOutPutFolder 	= "r:\\RRTesting\\DataOutput\\xe1";

vector<string> gModels;
void ProcessCommandLineArguments(int argc, char* argv[], Args& args);

//call with arguments, -m"modelFilePath" -r"resultFileFolder" -t"TempFolder" -lCompilerLocation
int main(int argc, char* argv[])
{
    Args args;
    ProcessCommandLineArguments(argc, argv, args);

    string reportFile(args.ResultOutputFile);

    gSBMLModelsPath 	= args.SBMLModelsFilePath;
	gCompilerPath 		= args.CompilerLocation;
	gSupportCodeFolder 	= args.SupportCodeFolder;

	fstream aFile(reportFile.c_str(), ios::out);
    if(!aFile)
    {
		cerr<<"Failed opening report file: "<<reportFile<<" in rr_cpp_api testing executable.\n";
    	return -1;
    }

	XmlTestReporter reporter1(aFile);
	TestRunner runner1(reporter1);

    runner1.RunTestsIf(Test::GetTestList(), "Base", 		True(), 0);
    runner1.RunTestsIf(Test::GetTestList(), "SteadyState", 	True(), 0);
    runner1.RunTestsIf(Test::GetTestList(), "SBML_l2v4",   	True(), 0);

    //Finish outputs result to xml file
    runner1.Finish();
    return 0;
}

void ProcessCommandLineArguments(int argc, char* argv[], Args& args)
{
    char c;
    while ((c = GetOptions(argc, argv, ("m:l:r:s:t:"))) != -1)
    {
        switch (c)
        {
            case ('m'): args.SBMLModelsFilePath                     = optarg;                       break;
			case ('l'): args.CompilerLocation                       = optarg;                       break;
            case ('r'): args.ResultOutputFile                       = optarg;                       break;
			case ('s'): args.SupportCodeFolder     		            = optarg;                       break;
			case ('t'): args.TempDataFolder        		            = optarg;                       break;
            case ('?'): cout<<Usage(argv[0])<<endl;
            default:
            {
                string str = argv[optind-1];
                if(str != "-?")
                {
                    cout<<"*** Illegal option:\t"<<argv[optind-1]<<" ***\n"<<endl;
                }
                exit(-1);
            }
        }
    }

    //Check arguments, and choose to bail here if something is not right...
    if(argc < 2)
    {
        cout<<Usage(argv[0])<<endl;
        exit(-1);
    }
}

#if defined(CG_IDE)
#pragma comment(lib, "roadrunner.lib")
#pragma comment(lib, "sundials_cvode.lib")
#pragma comment(lib, "sundials_nvecserial.lib")
#pragma comment(lib, "nleq-static.lib")
#pragma comment(lib, "rr-libstruct-static.lib")
#pragma comment(lib, "libsbml-static.lib")
#pragma comment(lib, "libxml2_xe.lib")
#pragma comment(lib, "blas.lib")
#pragma comment(lib, "lapack.lib")
#pragma comment(lib, "libf2c.lib")
#pragma comment(lib, "unit_test-static.lib")
#pragma comment(lib, "poco_foundation-static.lib")
#endif
