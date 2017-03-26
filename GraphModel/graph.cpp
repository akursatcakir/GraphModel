#include "graph.h"

#define _USE_MATH_DEFINES
#include <math.h>  

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Threading;

Graph::Vertice^ Graph::getVertice(int data) {
	for each (Vertice^ vertice in vertices)
	{
		if (vertice->data == data)
			return vertice;
	}
	return nullptr;
}

Graph::Vertice^ Graph::findVerticeFromPos(int x, int y) {
	for each (Vertice^ vertice in vertices)
	{
		if (sqrt(pow(vertice->x - x, 2) + pow(vertice->y - y, 2)) <= vertice->radius / 2)
			return vertice;
	}
	return nullptr;
}

void Graph::Delete() {
	for each (Vertice^ vertice in vertices)
		delete vertice;
	vertices.Clear();
}

void Graph::PlaceVertices(int width, int height) {
	unsigned int n = getVerticeCount();
	int size = width > height ? height : width;
	for each (Vertice^ vertice in vertices) {
		vertice->x = cos((double)vertice->data / (double)n * 2 * M_PI)*(double)size / 4 + size / 2;
		vertice->y = sin((double)vertice->data / (double)n * 2 * M_PI)*(double)size / 4 + size / 2;
	}
}

unsigned int Graph::getVerticeCount() {
	return vertices.Count;
}

int Graph::getNeighborCount(int data) {
	Vertice ^v = getVertice(data);
	if (v)
		return v->neighbors.Count;
	else return -1;
}

unsigned int Graph::getPathCount() {
	unsigned int count = 0;
	for each (Vertice^ vertice in vertices)
		count += vertice->neighbors.Count;
	return count / 2;
}

bool Graph::isComplete() {
	int n = vertices.Count;
	return (getPathCount() == n*(n - 1) / 2);
}

void Graph::LoadFromText(String^ text) {
	Delete();
	int verticeId = 0;
	for (int i = 0; i < text->Length; i++) {
		if (text[i] != '\n' && i != text->Length - 1)
			continue;
		Vertice^ v = gcnew Vertice(this);
		v->data = verticeId++;
		v->x = 0;
		v->y = 0;
		v->radius = 30;
		vertices.Add(v);
	}
	int thisId = 1;
	verticeId = 0;
	Vertice^ thisVertice = getVertice(0);
	String^ str = gcnew String("");
	for (int i = 0; i < text->Length; i++)
	{
		if (text[i] == ' ' || text[i] == '\n') {
			if (Convert::ToInt32(str) == 1)
				getVertice(verticeId)->neighbors.Add(thisVertice);

			verticeId++;
			str = "";
		}
		else str += text[i];
	
		if (text[i] == '\n') {
			thisVertice = getVertice(thisId);
			verticeId = 0;
			str = gcnew String("");
			thisId++;
		}
	}
}

void Graph::Paint(Graphics^ graphics) {
	graphics->Clear(Color::White);
	Pen^ verticePen = gcnew Pen(Color::Black);
	verticePen->Width = 1;
	Pen^ edgePen = gcnew Pen(Color::Blue);
	edgePen->Width = 1;
	SolidBrush^ brushWhite = gcnew SolidBrush(Color::White);
	SolidBrush^ brushGray = gcnew SolidBrush(Color::LightGray);
	SolidBrush^ brushBlack = gcnew SolidBrush(Color::Black);
	Font^ verticeFont = gcnew Font("Arial", 16);
	StringFormat^ drawFormat = gcnew StringFormat();
	for each (Vertice^ vertice in vertices)
		for each (Vertice^ neighbor in vertice->neighbors)
			graphics->DrawLine(edgePen, vertice->x, vertice->y, neighbor->x, neighbor->y);
	for each (Vertice^ vertice in vertices) {
		SizeF textSize = graphics->MeasureString(vertice->data.ToString(), verticeFont);
		SolidBrush^ verticeBrush;
		SolidBrush^ textBrush;
		switch (vertice->state)
		{
		case VertexState::White: 
			verticeBrush = brushWhite;
			textBrush = brushBlack;
			break;
		case VertexState::Gray: 
			verticeBrush = brushGray;
			textBrush = brushBlack;
			break;
		case VertexState::Black: 
			verticeBrush = brushBlack;
			textBrush = brushWhite;
			break;
		default:
			verticeBrush = brushWhite;
			textBrush = brushBlack;
			break;
		}
		graphics->FillEllipse(verticeBrush, (float)vertice->x - (float)vertice->radius / 2, (float)vertice->y - (float)vertice->radius / 2, (float)vertice->radius, (float)vertice->radius);
		graphics->DrawEllipse(verticePen, (float)vertice->x - (float)vertice->radius / 2, (float)vertice->y - (float)vertice->radius / 2, (float)vertice->radius, (float)vertice->radius);
		graphics->DrawString(vertice->data.ToString(), verticeFont, textBrush, vertice->x - textSize.Width / 2, vertice->y - textSize.Height / 2, drawFormat);
	}

}
void Graph::_dfs(int SleepTime) {
	time = 0;
	for each (Vertice^ vertice in vertices) {
		vertice->state = VertexState::White;
		vertice->reachTime = 0;
		vertice->processTime = 0;
	}
	for each (Vertice^ vertice in vertices)
		if(vertice->state == VertexState::White)
			runDFS(vertice, SleepTime);
}
void Graph::DFS() {
	_dfs(0);
}

void Graph::runDFS(Vertice^ vertice, int SleepTime) {
	vertice->reachTime = ++time;
	vertice->state = VertexState::Gray;
	
	if (SleepTime > 0) {
		if (reDrawFunc)
			reDrawFunc();
		System::Threading::Thread::Sleep(SleepTime);
	}
		
	for each (Vertice^ neighbor in vertice->neighbors)
		if (neighbor->state == VertexState::White)
			runDFS(neighbor, SleepTime);
	
	vertice->processTime = ++time;
	vertice->state = VertexState::Black;
	
	if (SleepTime > 0) {
		if (reDrawFunc)
			reDrawFunc();
		System::Threading::Thread::Sleep(SleepTime);
	}
}

void Graph::DFSThreadProc(Object^ obj)
{
	((Graph ^)obj)->_dfs(((Graph ^)obj)->SleepTime);
}

void Graph::DFSAsync() {
	Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(&Graph::DFSThreadProc));
	thread->Start(this);
}

void Graph::setReDrawFunc(ReDrawFunction func) {
	reDrawFunc = func;
}

void Graph::setStateChangedFunc(StateChangedFunction func) {
	stateChangedFunc = func;
}