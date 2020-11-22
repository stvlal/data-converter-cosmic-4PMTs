void tots() {

//gStyle->SetTitleColor(kBlue);
//gStyle->SetTitleTextColor(kBlue);
TCanvas *c = new TCanvas("c","c",600.,600.);
c->Divide(2,2);


TChain *fChain; //Define the input files chain
fChain = new TChain("t20");
fChain->Add("test.root");

c->cd(1);





TH1F *h_tot1 = new TH1F("h_tot1","h_tot1",100,0.,40.);

fChain->Draw("tot1 >> h_tot1","","goff");

c->cd(1);

h_tot1->SetName("ToT1 for Slab 1");
h_tot1->SetTitle("ToT1 for Slab 1");
h_tot1->GetXaxis()->SetTitle("ToT1 (ns)");
//h_tot1->GetXaxis()->SetTitleColor(kBlack);
h_tot1->SetLineColor(kBlue);
h_tot1->Draw();


TH1F *h_tot2 = new TH1F("h_tot2","h_tot2",100,0.,40.);

fChain->Draw("tot3 >> h_tot2","","goff");

c->cd(2);

h_tot2->SetName("ToT2 for Slab 1");
h_tot2->SetTitle("ToT2 for Slab 1");
h_tot2->GetXaxis()->SetTitle("ToT2 (ns)");
//h_tot2->GetXaxis()->SetTitleColor(kBlack);
h_tot2->SetLineColor(kBlue);

h_tot2->Draw();


//gStyle->SetTitleColor(kRed);
//gStyle->SetTitleTextColor(kRed);

TH1F *h_tot3 = new TH1F("h_tot3","h_tot3",100,0.,40.);

fChain->Draw("tot2 >> h_tot3","","goff");

c->cd(3);

h_tot3->SetName("ToT1 for Slab 2");
h_tot3->SetTitle("ToT1 for Slab 2");
h_tot3->GetXaxis()->SetTitle("ToT1 (ns)");
//h_tot3->GetXaxis()->SetTitleColor(kBlack);
h_tot3->SetLineColor(kRed);
h_tot3->Draw();


TH1F *h_tot4 = new TH1F("h_tot4","h_tot4",100,0.,40.);

fChain->Draw("tot0 >> h_tot4","","goff");

c->cd(4);

h_tot4->SetName("ToT2 for Slab 2");
h_tot4->SetTitle("ToT2 for Slab 2");
h_tot4->GetXaxis()->SetTitle("ToT2 (ns)");
//h_tot4->GetXaxis()->SetTitleColor(kBlack);
h_tot4->SetLineColor(kRed);
h_tot4->Draw();

//c->cd();
//TPaveText *title_h_tot1 = (TPaveText*)(c->cd(1)->GetPrimitive("title"));
//title->SetFillColor(kBlue);
//title_h_tot1->SetTextColor(kBlue);
// ->Modified();



c->Print("tots.pdf");

}
