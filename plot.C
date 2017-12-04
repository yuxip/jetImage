{
	gROOT->SetStyle("Plain");
	gStyle->SetTextFont(132);
	gStyle->SetLabelFont(132);
	gStyle->SetTitleFont(132);
	gStyle->SetFrameFillColor(0);
	gStyle->SetFrameFillStyle(0);
	gStyle->SetLegendBorderSize(0);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetFillColor(0);
	gStyle->SetFillStyle(0);
	gStyle->SetPadBorderMode(0);
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetCanvasColor(0);
	gStyle->SetFrameBorderMode(0);
	gStyle->SetLabelOffset(0.005, "x");
	gStyle->SetLabelOffset(0.005, "y");
	
	mg1 = new TCanvas("c1","canvas",500,450);
	mg1->cd();
	mg1->SetLogy();
	mg1->SetLogx();
	mg1->SetFillColor(0);
	mg1->SetFillStyle(0);
	mg1->SetMargin(0.15,0.15,0.15,0.15); // (left,right,bottom,top)

	TFile *file1 = new TFile("Jet_slow.root");
	h1 = (TH1F*)file1->Get("lightjet");
	h1->GetXaxis()->SetLabelFont(132);
	h1->GetYaxis()->SetLabelFont(132);
	h1->GetXaxis()->SetTitleFont(132);
	h1->GetYaxis()->SetTitleFont(132);
	h1->GetXaxis()->CenterTitle(true);
	h1->GetYaxis()->CenterTitle(true);
	h1->GetXaxis()->SetLimits(15.,515.);
	h1->GetYaxis()->SetRangeUser(0.1,1.E8);
	h1->GetXaxis()->SetTitleOffset(1.3); 
	h1->GetXaxis()->SetTitle("p_{T} (GeV)");
	h1->GetYaxis()->SetTitleOffset(1.4); 
	h1->GetYaxis()->SetTitle("d#sigma/dp_{T} (pb/GeV)");	
	h1->SetLineColor(2);
	h1->SetLineStyle(3);
	h1->Draw("][");

	TFile *file2 = new TFile("Jet_fast.root");
	h2 = (TH1F*)file2->Get("lightjet");
	h2->SetLineColor(4);
	h2->SetLineStyle(2);
	h2->Draw("][same");

	TFile *file3 = new TFile("Jet_cone.root");
	h3 = (TH1F*)file3->Get("lightjet");
	h3->SetLineColor(1);
	h3->SetLineStyle(1);
	h3->Draw("][same");

	TLegend *leg1 = new TLegend(0.5,0.65,0.75,0.78);
	leg1->SetTextFont(132); 
	leg1->SetTextSize(0.04);
	leg1->AddEntry(h1,"slow anti-k_{T}","l");
	leg1->AddEntry(h2,"fast anti-k_{T}","l");
	leg1->AddEntry(h3,"fast cone","l");
	leg1->Draw("same");
	
	TLatex *tex = new TLatex();
    tex->SetTextFont(132); 
    tex->SetTextSize(0.04);
    tex->DrawLatex(20,100,"light jets");
    tex->DrawLatex(20,10,"p+p collisions, LHC  #sqrt{s} = 7 TeV");
	tex->DrawLatex(20,2,"R=0.3   |y| < 2");

	c1->SaveAs("Jet_compare.ps");

}



