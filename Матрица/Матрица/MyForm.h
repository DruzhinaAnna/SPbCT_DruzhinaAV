#pragma once
#include<iostream>
using namespace std;

namespace Матрица {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->Location = System::Drawing::Point(12, 62);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Исходная матрица";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(170, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 120);
			this->dataGridView1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(17, 178);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 43);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Преобразованная матрица";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(170, 149);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(240, 116);
			this->dataGridView2->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 311);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int n=3, vec[20][20];
		//cin >> n;
		dataGridView1->RowCount = n;
		dataGridView1->ColumnCount = n;

		//cout << "Исходная матрица:" << endl;
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
			{
				vec[i][j] = rand() % 10;
				//cout << vec[i][j] << "  ";
				dataGridView1[i, j]->Value = vec[i][j];

			}
			//cout << endl;
		}
		//cout << endl;
		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = 3, vec[20][20];
		//cin >> n;
		dataGridView2->RowCount = n;
		dataGridView2->ColumnCount = n;
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
			{
				vec[i][j] = rand() % 10;
				//cout << vec[i][j] << "  ";
				dataGridView2[i, j]->Value = vec[i][j];

			}
			//cout << endl;
		}
		//cout << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = n - i; j < n; j++)
			{
				vec[i][j] = 0;
			}
		}
		//cout << endl;
		//cout << "Получившаяся матрица" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//cout << vec[i][j] << "  ";
				dataGridView2[i, j]->Value = vec[i][j];
			}
			//cout << endl;
		}

	}
};
}

