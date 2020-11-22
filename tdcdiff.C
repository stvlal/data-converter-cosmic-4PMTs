void tdcdiff() {

//gStyle->SetTitleColor(kBlue);
//gStyle->SetTitleTextColor(kBlue);
TCanvas *c = new TCanvas("c","c",400.,600.);
c->Divide(1,2);


TChain *fChain; //Define the input files chain
fChain = new TChain("t20");
fChain->Add("test.root");

c->cd(1);





TH1F *h_diff1 = new TH1F("h_diff1","h_diff1",100,-20.,20.);

fChain->Draw("(tdc1-tdc3) >> h_diff1","","goff");

c->cd(1);

h_diff1->SetName("(TDC1 - TDC2) for Slab 1");
h_diff1->SetTitle("(TDC1 - TDC2) for Slab 1");
h_diff1->GetXaxis()->SetTitle("TDC1-TDC2 (ns)");
//h_tot1->GetXaxis()->SetTitleColor(kBlack);
h_diff1->SetLineColor(kBlue);
h_diff1->Draw();


TH1F *h_diff2 = new TH1F("h_diff2","h_diff2",100,-20.,20.);

fChain->Draw("(tdc2-tdc0) >> h_diff2","","goff");

c->cd(2);

h_diff2->SetName("(TDC1 - TDC2) for Slab 2");
h_diff2->SetTitle("(TDC1 - TDC2) for Slab 2");
h_diff2->GetXaxis()->SetTitle("TDC1-TDC2 (ns)");
//h_tot1->GetXaxis()->SetTitleColor(kBlack);
h_diff2->SetLineColor(kRed);
h_diff2->Draw();


c->Print("tdcdiff.pdf");

}
