#pragma once

#include "utils.h"

namespace AngleVisualizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Input;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AngleVis : public System::Windows::Forms::Form
	{
	public:
		AngleVis(void)
		{
			InitializeComponent();
		}

		void update() {
			gr1->Clear(Color::White);
			gr1->DrawEllipse(Pens::Black, 0, 0, angle1->Width - 1, angle1->Height - 1);
			gr1->DrawLine(Pens::Black, 0, angle1->Height / 2, angle1->Width, angle1->Height / 2);
			gr1->DrawLine(Pens::Black, angle1->Width / 2, 0, angle1->Width / 2, angle1->Height);
			
			gr2->Clear(Color::White);
			gr2->DrawEllipse(Pens::Black, 0, 0, angle2->Width - 1, angle2->Height - 1);
			gr2->DrawLine(Pens::Black, 0, angle2->Height / 2, angle2->Width, angle2->Height / 2);
			gr2->DrawLine(Pens::Black, angle2->Width / 2, 0, angle2->Width / 2, angle2->Height);

			gr3->Clear(Color::White);
			gr3->DrawEllipse(Pens::Black, 0, 0, result->Width - 1, result->Height - 1);
			gr3->DrawLine(Pens::Black, 0, result->Height / 2, result->Width, result->Height / 2);
			gr3->DrawLine(Pens::Black, result->Width / 2, 0, result->Width / 2, result->Height);
			
			std::string a = Utils::toStdString(angleInput1->Text);
			if (Utils::isCorrectAngle(a)) {
				angle ang(a);
				double rad = ang.toRadians();
				gr1->DrawLine(gcnew Pen(Color::Red, 3) , angle1->Width / 2, angle1->Height / 2,
					(int)((angle1->Width / 2) * (cos(rad) + 1)), (int)((angle1->Height / 2) * (1 - sin(rad))));
			}
			
			a = Utils::toStdString(angleInput2->Text);
			if (Utils::isCorrectAngle(a)) {
				angle ang(a);
				double rad = ang.toRadians();
				gr2->DrawLine(gcnew Pen(Color::Red, 3), angle2->Width / 2, angle2->Height / 2,
					(int)((angle2->Width / 2) * (cos(rad) + 1)), (int)((angle2->Height / 2) * (1 - sin(rad))));
			}

			a = Utils::toStdString(resultOutput->Text);
			if (a!= "" && Utils::isCorrectAngle(a)) {
				angle ang(a);
				double rad = ang.toRadians();
				radians->Text = Utils::toSystemString(std::to_string(rad) + " rad");
				gr3->DrawLine(gcnew Pen(Color::Red, 3), result->Width / 2, result->Height / 2,
					(int)((result->Width / 2) * (cos(rad) + 1)), (int)((result->Height / 2) * (1 - sin(rad))));
			}
			
			angle1->Refresh();
			angle2->Refresh();
			result->Refresh();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AngleVis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Graphics^ gr1;
	private: Graphics^ gr2;
	private: Graphics^ gr3;
	private: System::Windows::Forms::TextBox^ angleInput1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ angle1;
	private: System::Windows::Forms::TableLayoutPanel^ panel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ angleInput2;
	private: System::Windows::Forms::PictureBox^ angle2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ resultOutput;
	private: System::Windows::Forms::PictureBox^ result;
	private: System::Windows::Forms::Button^ sum;
	private: System::Windows::Forms::Button^ diff;
	private: System::Windows::Forms::Label^ equal;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ angleMult1;
	private: System::Windows::Forms::Button^ angleDiv1;
	private: System::Windows::Forms::TextBox^ k1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Button^ angleMult2;
	private: System::Windows::Forms::Button^ angleDiv2;
	private: System::Windows::Forms::TextBox^ k2;
	private: System::Windows::Forms::TextBox^ radians;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->angleInput1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->angle1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->angleMult1 = (gcnew System::Windows::Forms::Button());
			this->angleDiv1 = (gcnew System::Windows::Forms::Button());
			this->k1 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->angleMult2 = (gcnew System::Windows::Forms::Button());
			this->angleDiv2 = (gcnew System::Windows::Forms::Button());
			this->k2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->angleInput2 = (gcnew System::Windows::Forms::TextBox());
			this->angle2 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->radians = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->resultOutput = (gcnew System::Windows::Forms::TextBox());
			this->result = (gcnew System::Windows::Forms::PictureBox());
			this->sum = (gcnew System::Windows::Forms::Button());
			this->diff = (gcnew System::Windows::Forms::Button());
			this->equal = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angle1))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angle2))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result))->BeginInit();
			this->SuspendLayout();
			// 
			// angleInput1
			// 
			this->angleInput1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->angleInput1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->angleInput1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->angleInput1->Location = System::Drawing::Point(93, 51);
			this->angleInput1->Name = L"angleInput1";
			this->angleInput1->Size = System::Drawing::Size(163, 22);
			this->angleInput1->TabIndex = 0;
			this->angleInput1->TabStop = false;
			this->angleInput1->Text = L"120d50m10s";
			this->angleInput1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->angleInput1->TextChanged += gcnew System::EventHandler(this, &AngleVis::angleInput1_TextChanged);
			this->angleInput1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AngleVis::angleInput1_KeyPress);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(4, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(341, 46);
			this->label1->TabIndex = 2;
			this->label1->Text = L"First circle";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// angle1
			// 
			this->angle1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->angle1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->angle1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->angle1->Location = System::Drawing::Point(4, 159);
			this->angle1->Name = L"angle1";
			this->angle1->Size = System::Drawing::Size(341, 307);
			this->angle1->TabIndex = 7;
			this->angle1->TabStop = false;
			this->angle1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AngleVis::angle1_MouseClick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->panel1->ColumnCount = 1;
			this->panel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->panel1->Controls->Add(this->label1, 0, 0);
			this->panel1->Controls->Add(this->angle1, 0, 3);
			this->panel1->Controls->Add(this->angleInput1, 0, 1);
			this->panel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->panel1->Location = System::Drawing::Point(45, 33);
			this->panel1->Name = L"panel1";
			this->panel1->RowCount = 4;
			this->panel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->panel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->panel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13)));
			this->panel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67)));
			this->panel1->Size = System::Drawing::Size(349, 470);
			this->panel1->TabIndex = 8;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->Controls->Add(this->angleMult1, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->angleDiv1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->k1, 1, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(4, 98);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(341, 54);
			this->tableLayoutPanel3->TabIndex = 8;
			// 
			// angleMult1
			// 
			this->angleMult1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->angleMult1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->angleMult1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->angleMult1->Location = System::Drawing::Point(281, 3);
			this->angleMult1->Name = L"angleMult1";
			this->angleMult1->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->angleMult1->Size = System::Drawing::Size(50, 48);
			this->angleMult1->TabIndex = 14;
			this->angleMult1->TabStop = false;
			this->angleMult1->Text = L"x";
			this->angleMult1->UseVisualStyleBackColor = true;
			this->angleMult1->Click += gcnew System::EventHandler(this, &AngleVis::angleMult1_Click);
			// 
			// angleDiv1
			// 
			this->angleDiv1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->angleDiv1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->angleDiv1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->angleDiv1->Location = System::Drawing::Point(9, 3);
			this->angleDiv1->Name = L"angleDiv1";
			this->angleDiv1->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->angleDiv1->Size = System::Drawing::Size(50, 48);
			this->angleDiv1->TabIndex = 14;
			this->angleDiv1->TabStop = false;
			this->angleDiv1->Text = L"/";
			this->angleDiv1->UseVisualStyleBackColor = true;
			this->angleDiv1->Click += gcnew System::EventHandler(this, &AngleVis::angleDiv1_Click);
			// 
			// k1
			// 
			this->k1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->k1->Location = System::Drawing::Point(104, 16);
			this->k1->Name = L"k1";
			this->k1->Size = System::Drawing::Size(132, 22);
			this->k1->TabIndex = 15;
			this->k1->TabStop = false;
			this->k1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AngleVis::k1_KeyPress);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::Control;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->angleInput2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->angle2, 0, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(477, 33);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(349, 465);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel4->Controls->Add(this->angleMult2, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->angleDiv2, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->k2, 1, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(4, 98);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(341, 53);
			this->tableLayoutPanel4->TabIndex = 14;
			// 
			// angleMult2
			// 
			this->angleMult2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->angleMult2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->angleMult2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->angleMult2->Location = System::Drawing::Point(281, 3);
			this->angleMult2->Name = L"angleMult2";
			this->angleMult2->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->angleMult2->Size = System::Drawing::Size(50, 47);
			this->angleMult2->TabIndex = 14;
			this->angleMult2->TabStop = false;
			this->angleMult2->Text = L"x";
			this->angleMult2->UseVisualStyleBackColor = true;
			this->angleMult2->Click += gcnew System::EventHandler(this, &AngleVis::angleMult2_Click);
			// 
			// angleDiv2
			// 
			this->angleDiv2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->angleDiv2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->angleDiv2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->angleDiv2->Location = System::Drawing::Point(9, 3);
			this->angleDiv2->Name = L"angleDiv2";
			this->angleDiv2->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->angleDiv2->Size = System::Drawing::Size(50, 47);
			this->angleDiv2->TabIndex = 14;
			this->angleDiv2->TabStop = false;
			this->angleDiv2->Text = L"/";
			this->angleDiv2->UseVisualStyleBackColor = true;
			this->angleDiv2->Click += gcnew System::EventHandler(this, &AngleVis::angleDiv2_Click);
			// 
			// k2
			// 
			this->k2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->k2->Location = System::Drawing::Point(104, 15);
			this->k2->Name = L"k2";
			this->k2->Size = System::Drawing::Size(132, 22);
			this->k2->TabIndex = 15;
			this->k2->TabStop = false;
			this->k2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AngleVis::k2_KeyPress);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(4, 1);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(341, 46);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Second circle";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// angleInput2
			// 
			this->angleInput2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->angleInput2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->angleInput2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->angleInput2->Location = System::Drawing::Point(93, 51);
			this->angleInput2->Name = L"angleInput2";
			this->angleInput2->Size = System::Drawing::Size(163, 22);
			this->angleInput2->TabIndex = 0;
			this->angleInput2->TabStop = false;
			this->angleInput2->Text = L"50d10m";
			this->angleInput2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->angleInput2->TextChanged += gcnew System::EventHandler(this, &AngleVis::angleInput2_TextChanged);
			this->angleInput2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AngleVis::angleInput2_KeyPress);
			// 
			// angle2
			// 
			this->angle2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->angle2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->angle2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->angle2->Location = System::Drawing::Point(4, 158);
			this->angle2->Name = L"angle2";
			this->angle2->Size = System::Drawing::Size(341, 303);
			this->angle2->TabIndex = 7;
			this->angle2->TabStop = false;
			this->angle2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AngleVis::angle2_MouseClick);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::SystemColors::Control;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->radians, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->resultOutput, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->result, 0, 3);
			this->tableLayoutPanel2->Location = System::Drawing::Point(940, 34);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(349, 460);
			this->tableLayoutPanel2->TabIndex = 10;
			// 
			// radians
			// 
			this->radians->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->radians->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->radians->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radians->Location = System::Drawing::Point(48, 111);
			this->radians->Name = L"radians";
			this->radians->ReadOnly = true;
			this->radians->Size = System::Drawing::Size(253, 22);
			this->radians->TabIndex = 14;
			this->radians->TabStop = false;
			this->radians->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(4, 1);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(341, 45);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Result circle";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resultOutput
			// 
			this->resultOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->resultOutput->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->resultOutput->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->resultOutput->Location = System::Drawing::Point(93, 50);
			this->resultOutput->Name = L"resultOutput";
			this->resultOutput->ReadOnly = true;
			this->resultOutput->Size = System::Drawing::Size(163, 22);
			this->resultOutput->TabIndex = 0;
			this->resultOutput->TabStop = false;
			this->resultOutput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->resultOutput->TextChanged += gcnew System::EventHandler(this, &AngleVis::resultOutput_TextChanged);
			// 
			// result
			// 
			this->result->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->result->BackColor = System::Drawing::SystemColors::ControlLight;
			this->result->Cursor = System::Windows::Forms::Cursors::Cross;
			this->result->Location = System::Drawing::Point(4, 156);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(341, 300);
			this->result->TabIndex = 7;
			this->result->TabStop = false;
			// 
			// sum
			// 
			this->sum->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sum->Location = System::Drawing::Point(409, 162);
			this->sum->Name = L"sum";
			this->sum->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->sum->Size = System::Drawing::Size(50, 50);
			this->sum->TabIndex = 11;
			this->sum->TabStop = false;
			this->sum->Text = L"+";
			this->sum->UseVisualStyleBackColor = true;
			this->sum->Click += gcnew System::EventHandler(this, &AngleVis::sum_Click);
			// 
			// diff
			// 
			this->diff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->diff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->diff->Location = System::Drawing::Point(409, 229);
			this->diff->Name = L"diff";
			this->diff->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->diff->Size = System::Drawing::Size(50, 50);
			this->diff->TabIndex = 12;
			this->diff->TabStop = false;
			this->diff->Text = L"-";
			this->diff->UseVisualStyleBackColor = true;
			this->diff->Click += gcnew System::EventHandler(this, &AngleVis::diff_Click);
			// 
			// equal
			// 
			this->equal->AutoSize = true;
			this->equal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->equal->Location = System::Drawing::Point(847, 192);
			this->equal->Name = L"equal";
			this->equal->Size = System::Drawing::Size(66, 69);
			this->equal->TabIndex = 13;
			this->equal->Text = L"=";
			// 
			// AngleVis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1335, 553);
			this->Controls->Add(this->equal);
			this->Controls->Add(this->diff);
			this->Controls->Add(this->sum);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AngleVis";
			this->ShowIcon = false;
			this->Text = L"AngleVisualizer";
			this->Load += gcnew System::EventHandler(this, &AngleVis::AngleVis_Load);
			this->Click += gcnew System::EventHandler(this, &AngleVis::AngleVis_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angle1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angle2))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AngleVis_Load(System::Object^ sender, System::EventArgs^ e) {
		angle1->Image = gcnew Bitmap(angle1->Width, angle1->Height);
		gr1 = Graphics::FromImage(angle1->Image);
		angle2->Image = gcnew Bitmap(angle2->Width, angle2->Height);
		gr2 = Graphics::FromImage(angle2->Image);
		result->Image = gcnew Bitmap(result->Width, result->Height);
		gr3 = Graphics::FromImage(result->Image);
		update();
	}
	private: System::Void angleInput1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char sym = (char)e->KeyChar;
		std::string a = Utils::toStdString(angleInput1->Text);
		e->Handled = !((sym == 'd' || sym == 'm' || sym == 's') && Utils::getSymbolCount(a, sym) == 0)
			&& !Char::IsControl(sym) && !Char::IsDigit(sym) && !(sym == '-');
	}
	private: System::Void angleInput1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		update();
	}	
	private: System::Void angle1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Point cords = e->Location;
		double x = cords.X - angle1->Width / 2; double y = angle1->Height / 2 - cords.Y;
		angleInput1->Text = Utils::toSystemString(angle(x, y).ToString());
	}
	private: System::Void AngleVis_Click(System::Object^ sender, System::EventArgs^ e) {
		angleInput1->Text = Utils::toSystemString(angle(Utils::toStdString(angleInput1->Text)).ToString());
		angleInput2->Text = Utils::toSystemString(angle(Utils::toStdString(angleInput2->Text)).ToString());
		label1->Focus();
	}
	private: System::Void angleInput2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char sym = (char)e->KeyChar;
		std::string a = Utils::toStdString(angleInput2->Text);
		e->Handled = !((sym == 'd' || sym == 'm' || sym == 's') && Utils::getSymbolCount(a, sym) == 0)
			&& !Char::IsControl(sym) && !Char::IsDigit(sym) && !(sym == '-');
	}
	private: System::Void angleInput2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		update();
	}
	private: System::Void angle2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Point cords = e->Location;
		double x = cords.X - angle2->Width / 2; double y = angle2->Height / 2 - cords.Y;
		angleInput2->Text = Utils::toSystemString(angle(x, y).ToString());
	}
	private: System::Void sum_Click(System::Object^ sender, System::EventArgs^ e) {
		angle a1(Utils::toStdString(angleInput1->Text));
		angle a2(Utils::toStdString(angleInput2->Text));
		angle res = a1 + a2;
		resultOutput->Text = Utils::toSystemString(res.ToString());
		update();
		label1->Focus();
	}
	private: System::Void diff_Click(System::Object^ sender, System::EventArgs^ e) {
		angle a1(Utils::toStdString(angleInput1->Text));
		angle a2(Utils::toStdString(angleInput2->Text));
		angle res = a1 - a2;
		resultOutput->Text = Utils::toSystemString(res.ToString());
		update();
		label1->Focus();
	}
	private: System::Void resultOutput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		update();
	}
	private: System::Void k1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		e->Handled = !Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar);
	}
	private: System::Void angleMult1_Click(System::Object^ sender, System::EventArgs^ e) {
		angle a1(Utils::toStdString(angleInput1->Text));
		int mult = 1;
		if (k1->Text != "")
			mult = Convert::ToInt32(k1->Text);
		angle res = a1 * mult;
		angleInput1->Text = Utils::toSystemString(res.ToString());
		update();
		label1->Focus();
	}
	private: System::Void angleDiv1_Click(System::Object^ sender, System::EventArgs^ e) {
		angle a1(Utils::toStdString(angleInput1->Text));
		int div = 1;
		if (k1->Text != "") {
			div = Convert::ToInt32(k1->Text);
			if (div == 0) div = 1;
		}
		angle res = a1 / div;
		angleInput1->Text = Utils::toSystemString(res.ToString());
		update();
		label1->Focus();
	}
	private: System::Void k2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		e->Handled = !Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar);
	}
	private: System::Void angleMult2_Click(System::Object^ sender, System::EventArgs^ e) {
		angle a1(Utils::toStdString(angleInput2->Text));
		int mult = 1;
		if (k1->Text != "")
			mult = Convert::ToInt32(k2->Text);
		angle res = a1 * mult;
		angleInput2->Text = Utils::toSystemString(res.ToString());
		update();
		label1->Focus();
	}
	private: System::Void angleDiv2_Click(System::Object^ sender, System::EventArgs^ e) {
		angle a1(Utils::toStdString(angleInput2->Text));
		int div = 1;
		if (k2->Text != "") {
			div = Convert::ToInt32(k2->Text);
			if (div == 0) div = 1;
		}
		angle res = a1 / div;
		angleInput2->Text = Utils::toSystemString(res.ToString());
		update();
		label1->Focus();
	}
};
}