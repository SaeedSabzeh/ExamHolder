﻿#pragma once

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PRO_SIGN
	/// </summary>
	public ref class PRO_SIGN : public System::Windows::Forms::Form
	{
	public:
		PRO_SIGN(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PRO_SIGN()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(217, 286);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(352, 38);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(217, 376);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(352, 38);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->AcceptsReturn = true;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(217, 468);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(352, 38);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(217, 197);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(352, 38);
			this->textBox4->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"B Titr", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label6->Location = System::Drawing::Point(467, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(193, 65);
			this->label6->TabIndex = 15;
			this->label6->Text = L"ثبت نام مدیر";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"_MRT_Khodkar", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label3->Location = System::Drawing::Point(735, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 51);
			this->label3->TabIndex = 16;
			this->label3->Text = L"نام";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"_MRT_Khodkar", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label4->Location = System::Drawing::Point(657, 273);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 51);
			this->label4->TabIndex = 17;
			this->label4->Text = L"نام خانوادگی";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"_MRT_Khodkar", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label1->Location = System::Drawing::Point(672, 363);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 51);
			this->label1->TabIndex = 18;
			this->label1->Text = L"نام کاربری";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"_MRT_Khodkar", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label2->Location = System::Drawing::Point(691, 455);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 51);
			this->label2->TabIndex = 19;
			this->label2->Text = L"رمز عبور";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"B Nazanin", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->button1->Location = System::Drawing::Point(406, 559);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 46);
			this->button1->TabIndex = 20;
			this->button1->Text = L"ثبت اطلاعات";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PRO_SIGN::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"B Nazanin", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->button2->Location = System::Drawing::Point(217, 559);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 46);
			this->button2->TabIndex = 21;
			this->button2->Text = L"بازگشت";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PRO_SIGN::button2_Click_1);
			// 
			// PRO_SIGN
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1178, 735);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"PRO_SIGN";
			this->Text = L"PRO_SIGN";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
