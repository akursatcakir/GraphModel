#pragma once
#include "graph.h"

namespace GraphModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for fMain
	/// </summary>
	public ref class fMain : public System::Windows::Forms::Form
	{
	public:
		fMain(void)
		{
			InitializeComponent();
			InitializeGraph();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~fMain()
		{
			if (components)
			{
				delete components;
			}
			delete GRAPH;
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  graphToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deepFirstSearchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::ToolStripMenuItem^  placeAgainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  drawToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ListBox^  lbGraphStatus;
	private: System::Windows::Forms::Panel^  pDrawingContainer;
	private: System::Windows::Forms::PropertyGrid^  pg;


	private: System::Windows::Forms::Splitter^  splitter2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Splitter^  splitter3;
	private: System::Windows::Forms::TreeView^  tv;

	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::ToolStripMenuItem^  breadthFirstSearchToolStripMenuItem;














			 Graph ^GRAPH;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Graph"));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->graphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deepFirstSearchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->placeAgainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lbGraphStatus = (gcnew System::Windows::Forms::ListBox());
			this->pDrawingContainer = (gcnew System::Windows::Forms::Panel());
			this->pg = (gcnew System::Windows::Forms::PropertyGrid());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->splitter3 = (gcnew System::Windows::Forms::Splitter());
			this->tv = (gcnew System::Windows::Forms::TreeView());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->breadthFirstSearchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->graphToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(647, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->clearToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::openToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::clearToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::exitToolStripMenuItem_Click);
			// 
			// graphToolStripMenuItem
			// 
			this->graphToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->deepFirstSearchToolStripMenuItem,
					this->breadthFirstSearchToolStripMenuItem, this->placeAgainToolStripMenuItem, this->drawToolStripMenuItem
			});
			this->graphToolStripMenuItem->Name = L"graphToolStripMenuItem";
			this->graphToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->graphToolStripMenuItem->Text = L"Graph";
			// 
			// deepFirstSearchToolStripMenuItem
			// 
			this->deepFirstSearchToolStripMenuItem->Name = L"deepFirstSearchToolStripMenuItem";
			this->deepFirstSearchToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->deepFirstSearchToolStripMenuItem->Text = L"Deep First Search";
			this->deepFirstSearchToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::deepFirstSearchToolStripMenuItem_Click);
			// 
			// placeAgainToolStripMenuItem
			// 
			this->placeAgainToolStripMenuItem->Name = L"placeAgainToolStripMenuItem";
			this->placeAgainToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->placeAgainToolStripMenuItem->Text = L"Place Vertices";
			this->placeAgainToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::placeAgainToolStripMenuItem_Click);
			// 
			// drawToolStripMenuItem
			// 
			this->drawToolStripMenuItem->Name = L"drawToolStripMenuItem";
			this->drawToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->drawToolStripMenuItem->Text = L"Refresh Screen";
			this->drawToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::drawToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Text files|*.txt";
			// 
			// lbGraphStatus
			// 
			this->lbGraphStatus->Dock = System::Windows::Forms::DockStyle::Right;
			this->lbGraphStatus->FormattingEnabled = true;
			this->lbGraphStatus->Location = System::Drawing::Point(447, 24);
			this->lbGraphStatus->Name = L"lbGraphStatus";
			this->lbGraphStatus->Size = System::Drawing::Size(200, 465);
			this->lbGraphStatus->TabIndex = 1;
			// 
			// pDrawingContainer
			// 
			this->pDrawingContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pDrawingContainer->Location = System::Drawing::Point(200, 24);
			this->pDrawingContainer->Name = L"pDrawingContainer";
			this->pDrawingContainer->Size = System::Drawing::Size(247, 465);
			this->pDrawingContainer->TabIndex = 2;
			this->pDrawingContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &fMain::pDrawingContainer_Paint);
			this->pDrawingContainer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &fMain::pDrawingContainer_MouseDown);
			this->pDrawingContainer->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &fMain::pDrawingContainer_MouseMove);
			// 
			// pg
			// 
			this->pg->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pg->Location = System::Drawing::Point(0, 65);
			this->pg->Name = L"pg";
			this->pg->Size = System::Drawing::Size(200, 400);
			this->pg->TabIndex = 3;
			// 
			// splitter2
			// 
			this->splitter2->Dock = System::Windows::Forms::DockStyle::Right;
			this->splitter2->Location = System::Drawing::Point(444, 24);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(3, 465);
			this->splitter2->TabIndex = 5;
			this->splitter2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->splitter3);
			this->panel1->Controls->Add(this->tv);
			this->panel1->Controls->Add(this->pg);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 465);
			this->panel1->TabIndex = 0;
			// 
			// splitter3
			// 
			this->splitter3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->splitter3->Location = System::Drawing::Point(0, 62);
			this->splitter3->Name = L"splitter3";
			this->splitter3->Size = System::Drawing::Size(200, 3);
			this->splitter3->TabIndex = 5;
			this->splitter3->TabStop = false;
			// 
			// tv
			// 
			this->tv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tv->HideSelection = false;
			this->tv->Location = System::Drawing::Point(0, 0);
			this->tv->Name = L"tv";
			treeNode1->Name = L"root";
			treeNode1->Text = L"Graph";
			this->tv->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 });
			this->tv->Size = System::Drawing::Size(200, 65);
			this->tv->TabIndex = 4;
			this->tv->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &fMain::tv_AfterSelect);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(200, 24);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 465);
			this->splitter1->TabIndex = 6;
			this->splitter1->TabStop = false;
			// 
			// breadthFirstSearchToolStripMenuItem
			// 
			this->breadthFirstSearchToolStripMenuItem->Name = L"breadthFirstSearchToolStripMenuItem";
			this->breadthFirstSearchToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->breadthFirstSearchToolStripMenuItem->Text = L"Breadth First Search";
			this->breadthFirstSearchToolStripMenuItem->Click += gcnew System::EventHandler(this, &fMain::breadthFirstSearchToolStripMenuItem_Click);
			// 
			// fMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(647, 489);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->pDrawingContainer);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lbGraphStatus);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"fMain";
			this->Text = L"Graph";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void InitializeGraph() {
	GRAPH = gcnew Graph();
	GRAPH->SleepTime = 1000;
	GRAPH->setReDrawFunc(gcnew Action(this, &fMain::ReDraw));
	GRAPH->setStateChangedFunc(gcnew Action<Graph::Vertice^>(this, &fMain::OnStateChanged));
	tv->Nodes[0]->Tag = GRAPH;
	tv->SelectedNode = tv->Nodes[0];
}

private: System::Void FillList() {
	tv->Nodes[0]->Nodes->Clear();

	for each(Graph::Vertice^ v in GRAPH->vertices) {
		TreeNode ^node = gcnew TreeNode("Vertice " + v->data.ToString());
		node->Name = "vertice" + v->data.ToString();
		node->Tag = v;
		tv->Nodes[0]->Nodes->Add(node);
	}
}

private:
	delegate void ReDrawDelegate();
void ReDrawFunc() {
	this->pDrawingContainer->Invalidate();
	this->pDrawingContainer->Update();
	pg->Refresh();
}
private: void ReDraw() {
	if (this->InvokeRequired)
		this->Invoke(gcnew ReDrawDelegate(this, &fMain::ReDrawFunc));
	else ReDrawFunc();
}
private:
	delegate void OnStateChangedDelegate(Graph::Vertice^ vertice);
void OnStateChangedFunc(Graph::Vertice^ vertice) {
	if (vertice->state == Graph::VertexState::White) return;
	lbGraphStatus->Items->Add((vertice->state == Graph::VertexState::Gray ? vertice->reachTime : vertice->processTime).ToString() + ": Node " + vertice->data.ToString() + " is " + (vertice->state == Graph::VertexState::Gray ? "reached" : "processed"));
}
private: void OnStateChanged(Graph::Vertice^ vertice) {
	if (this->InvokeRequired)
		this->Invoke(gcnew OnStateChangedDelegate(this, &fMain::OnStateChangedFunc), vertice);
	else OnStateChangedFunc(vertice);
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::IO::StreamReader ^ sr = gcnew
			System::IO::StreamReader(openFileDialog1->FileName);
		GRAPH->LoadFromText(sr->ReadToEnd());
		sr->Close();
		FillList();
		GRAPH->PlaceVertices(pDrawingContainer->Width, pDrawingContainer->Height);
	}
}
private: System::Void deepFirstSearchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	lbGraphStatus->Items->Clear();
	if (GRAPH->VerticeCount > 0)
		GRAPH->TraversalAsync(Graph::TraversalAlgorithm::DFS);
	else MessageBox::Show("Graph is empty!");
}
private: System::Void drawToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ReDraw();
}
private: System::Void placeAgainToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	GRAPH->PlaceVertices(pDrawingContainer->Width, pDrawingContainer->Height);
}
private: Point MouseDownLocation;
private: Graph::Vertice^ MouseDownVertice;
private: System::Void clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	GRAPH->Delete();
	FillList();
	ReDraw();
}
private: System::Void pDrawingContainer_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	GRAPH->Paint(e->Graphics);
}
private: System::Void pDrawingContainer_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left && MouseDownVertice)
	{
		MouseDownVertice->x += e->X - MouseDownLocation.X;
		MouseDownVertice->y += e->Y - MouseDownLocation.Y;
		MouseDownLocation = e->Location;
	}
}
private: System::Void pDrawingContainer_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		MouseDownLocation = e->Location;
		MouseDownVertice = GRAPH->findVerticeFromPos(e->Location.X, e->Location.Y);
		if (MouseDownVertice)
			tv->SelectedNode = tv->Nodes[0]->Nodes->Find("vertice" + MouseDownVertice->data.ToString(), false)[0];
		else
			tv->SelectedNode = tv->Nodes[0];
	}
}
private: System::Void tv_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
	pg->SelectedObject = tv->SelectedNode->Tag;
}

private: System::Void breadthFirstSearchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	lbGraphStatus->Items->Clear();
	if (GRAPH->VerticeCount > 0)
		GRAPH->TraversalAsync(Graph::TraversalAlgorithm::BFS);
	else MessageBox::Show("Graph is empty!");
}
};
}
