

using namespace std;

#include "trb3.h" // The definition of the input files three and necessary classes

#include "t20.h" // The definition of the output file three



int main(int argc, char** argv) {

//TApplication *theApp = new TApplication("App", &argc, argv);
//This option is needed if graphics (such as canvases) is used


if ((string(argv[1]) == "-h")) {
      
        std::cerr << "Usage: -i <input_file1> <input_file2> ... -o <output_file> " << std::endl;
       
        return 1;
    } 

if ((argc < 5)||(string(argv[1]) != "-i")||(string(argv[argc-2]) != "-o")) {
      
        std::cerr << "Usage: -i <input_file1> <input_file2> ... -o <output_file> " << std::endl;
       
        return 1;
    } // Checking for right usage of the command line options



unsigned long N=0; // Number of good (survived) events

Int_t chan0 = 23; //Channel for PMT 0
Int_t chan1 = 24; //Channel for PMT 1
Int_t chan2 = 25; //Channel for PMT 2
Int_t chan3 = 26; //Channel for PMT 3


trb3 new_trb; //Define variable of the class trb3




TChain *fChain; //Define the input files chain
fChain = new TChain("T");

for (Int_t i = 2; i < argc-2; i++) {
cout << argv[i] << endl;
fChain->Add(argv[i]);
}; //Adding input files into the chain




//Long64_t entry = fChain->GetEntries();
//cout << "N enteries = " << entry << endl; 
//Printing out number of entries in the chain

new_trb.Init(fChain); //Initialization of a new chain (branch addresses and branch pointers set)

        TFile *outFile = new TFile(argv[argc-1],"recreate");
	//Creating the output file
	
        t20->Branch("eventn",&eventn,"tot0/D:tot1/D:tot2/D:tot3/D:tdc0/D:tdc1/D:tdc2/D:tdc3/D");
	//Define output three branches 	


	
//for(Long64_t i=0;i<=entry;i++) {



new_trb.Process(N, chan0, chan1, chan2, chan3); 



//};
//Looping over entries in the input files


t20->Write("", TObject::kOverwrite);
//Writing down the output three

outFile->Close(); 
//Closing the output file


//  theApp->Run(kTRUE); 
//This option is needed if graphics (such as canvases) is used (see the definition of theApp above)

 cout << "Number of good (survived) events = " << N << endl;
  
  return 0;
 

};




Bool_t trb3::Process(unsigned long &N,Int_t chan0,Int_t chan1, Int_t chan2, Int_t chan3)
{


Long64_t entry= 0;

//fChain->GetEntry(entry);
//Taking the entry from the chain

//Double_t adc00,tdc00;  // Declaring ToT and TDC for PMT 0

while (fReader.Next()) {

fReader.SetEntry(entry);


Int_t Hits_ = Hits_nTdcChannel.GetSize();
 
if(entry%100000==0) printf("+%ld %d\n",(long)entry,Hits_);
//Printing out for each 100000 entries
 

int Kk=(Hits_-1); // Number of hits in the entry (-1 since hit zero is reserved for header)

if (Hits_ >= 9) { // Number of hits should be greater than 9. Hit zero reserved for header, two hits for PMT 1 front and rear edge times,  two hits for PMT 2 front and rear edge times, etc...


for(int i0=1;i0<=Kk-7;i0++) // Searching for PMT 0 front edge hit
   {  

   if ((Hits_nTdcChannel[i0] == chan0)&&(Hits_nSignalEdge[i0]==1)) { // Checking the channel number

for(int j0=i0+1;j0<=Kk-6;j0++) // Searching for PMT 0 rear edge hit
   {   
   
   if ((Hits_nTdcChannel[j0] == chan0)&&(Hits_nSignalEdge[j0]==0)) { // Checking the channel number
   
   if (Hits_nEpochCounter[i0] == Hits_nEpochCounter[j0]) { // Checking that both hits are from the same physical event. 
   
   
   
for(int i1=j0+1;i1<=Kk-5;i1++) // Searching for PMT 1 front edge hit
   {  
   
   if ((Hits_nTdcChannel[i1] == chan1)&&(Hits_nSignalEdge[i1]==1)) { // Checking the channel number
   
   if (Hits_nEpochCounter[j0] == Hits_nEpochCounter[i1]) { // Checking that hit came from the same physical event as previous two.

for(int j1=i1+1;j1<=Kk-4;j1++) // Searching for PMT 1 rear edge hit
   {   
    
   if ((Hits_nTdcChannel[j1] == chan1)&&(Hits_nSignalEdge[j1]==0)) { // Checking the channel number

   if (Hits_nEpochCounter[i1] == Hits_nEpochCounter[j1]) {  // Checking that hit came from the same physical event as previous three.  
   
   
for(int i2=j1+1;i2<=Kk-3;i2++) // Searching for PMT 2 front edge hit
   {  
   
   if ((Hits_nTdcChannel[i2] == chan2)&&(Hits_nSignalEdge[i2]==1)) { // Checking the channel number
   
   if (Hits_nEpochCounter[j1] == Hits_nEpochCounter[i2]) { // Checking that hit came from the same physical event as previous two.

for(int j2=i2+1;j2<=Kk-2;j2++) // Searching for PMT 2 rear edge hit
   {   
    
   if ((Hits_nTdcChannel[j2] == chan2)&&(Hits_nSignalEdge[j2]==0)) { // Checking the channel number

   if (Hits_nEpochCounter[i2] == Hits_nEpochCounter[j2]) {  // Checking that hit came from the same physical event as previous three.  


for(int i3=j2+1;i3<=Kk-1;i3++) // Searching for PMT 3 front edge hit
   {  
   
   if ((Hits_nTdcChannel[i3] == chan3)&&(Hits_nSignalEdge[i3]==1)) { // Checking the channel number
   
   if (Hits_nEpochCounter[j2] == Hits_nEpochCounter[i3]) { // Checking that hit came from the same physical event as previous two.

for(int j3=i3+1;j3<=Kk;j3++) // Searching for PMT 3 rear edge hit
   {   
    
   if ((Hits_nTdcChannel[j3] == chan3)&&(Hits_nSignalEdge[j3]==0)) { // Checking the channel number

   if (Hits_nEpochCounter[i3] == Hits_nEpochCounter[j3]) {  // Checking that hit came from the same physical event as previous three.  



      eventn.tot0 = Hits_fTime[j0]-Hits_fTime[i0]-(57.4-30.);  // Calculating adc0 as the difference between PMT 0 rear edge time and PMT 0 front edge time (time-over-threshold method).            
      eventn.tot1 = Hits_fTime[j1]-Hits_fTime[i1]-(57.87-30.);; // Calculating adc1 as the difference between PMT 1 rear edge time and PMT 1 front edge time (time-over-threshold method).      
      eventn.tot2 = Hits_fTime[j2]-Hits_fTime[i2]-(57.87-30.);; // Calculating adc2 as the difference between PMT 2 rear edge time and PMT 2 front edge time (time-over-threshold method).  
      eventn.tot3 = Hits_fTime[j3]-Hits_fTime[i3]-(57.87-30.);; // Calculating adc3 as the difference between PMT 3 rear edge time and PMT 3 front edge time (time-over-threshold method).            
      
      eventn.tdc0 = Hits_fTime[i0];; // Define tdc0 as PMT 0 front edge time
      eventn.tdc1 = Hits_fTime[i1]; // Define tdc1 as PMT 1 front edge time
      eventn.tdc2 = Hits_fTime[i2]; // Define tdc2 as PMT 2 front edge time
      eventn.tdc3 = Hits_fTime[i3]; // Define tdc2 as PMT 2 front edge time    
      
      t20->Fill(); //Filling out the output three


 
   N++; //Increment of the number of good (survived) events
	 
	       
         }; // end of channels match if
         }; // end of EpochCounters match if  

   };
   };
   };
   };
   };
   };

   };
   };
   };
   };
   };
   };
   
   };
   };
   };
   };
   };
   }; // end of loop over the hits
   };
   };
   };
   }; // end of number of hits >= 9 if
   entry++;
   }; // end of entry (while) loop
   
return kTRUE;
}

