#include"exam_English.h"
#include"utility.h"
#include<random>
using namespace std;

//�p�P��̖����쐬����
QuestionList CreateEnglishWordExam()
{
	 const struct {
		const char* word; //�ǂ�
		const char* reading; //�ǂ�
		const char* meaning; //�Ӗ�
	 }data[] = {
		 {"state", "�X�e�[�g", "���"},
		 {"business", "�r�W�l�X", "�d��"},
		 {"abstract", "�A�u�X�g���N�g", "���ۓI��"},
		 {"concrete", "�R���N���[�g", "��̓I��"},
		 {"digital", "�f�W�^��", "�����ŏ���`����"},
		 {"analogue", "�A�i���O", "�ގ����Ă�����́A�ގ���"},
		 {"exchange", "�G�N�X�`�F���W", "�����A���ցA�ב�"},
		 {"infrastructure", "�C���t���X�g���N�`��", "�����\���A��b�ƂȂ�{�݂�ݔ�"},
		 {"knowledge", "�i���b�W", "�m��"},
		 {"credit", "�N���W�b�g", "�M�p"},
		 {"routine", "���[�e�B��", "���܂����菇"},
		 {"management", "�}�l�W�����g", "�Ǘ��o�c"},
		 {"account", "�A�J�E���g", "��v�A����"},
		 {"unique", "���j�[�N", "���ɗނ����Ȃ��A���I��"},
		 {"variety", "�o���G�e�B", "�ω��ɕx�ށA���ʂ�"},
		 {"schedule", "�X�P�W���[��", "�\��A�v��"},
		 {"agenda", "�A�W�F���_", "�ۑ�A�c��"},
		 {"technology", "�e�N�m���W�[", "�Ȋw�Z�p"},
		 {"collaboration", "�R���{���[�V����", "���́A�������ƁA�������"},
		 {"tax", "�^�b�N�X", "�ŋ�"},
		 {"stock", "�X�g�b�N", "�݌ɁA����"},
		 {"product", "�v���_�N�g", "���i"},
		 {"booking", "�u�b�L���O", "�\��A����ւ̋L��"},
		 {"weight", "�E�F�C�g", "�d��"},
		 {"compliance", "�R���v���C�A���X", "�@�ߎЉ�I�K�͂����"},
		 {"receipt", "���V�[�g", "�̎���"},
		 
	 };

	 constexpr int quizCount = 26;
	 QuestionList questions;
	 questions.reserve(quizCount);
	 const vector<int> indices = CreateRandomIndices(size(data));
	 random_device rd;


	 //���̎�ނ������_���ɑI��
	 const int type = uniform_int_distribution<>(0, 3)(rd);
	 switch (type) {
	 case 0://�Ӗ�����p�P��𓚂���
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];
			 questions.push_back({
				 "�u" + string(e.meaning) + "�v���Ӗ�����p�P��𓚂���",
				 e.word });
		 }
		 break;
	 case 1: //�ǂ݂���p�P��𓚂���
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];
			 questions.push_back({
				 "�J�^�J�i�̓ǂ݁u" + string(e.meaning) + "�v��Ή�����p�P��𓚂���",
				 e.word });
		 }

		 break;
	 case 2: //�p�P�ꂩ��ǂ݂𓚂���
		 for (int i = 0; i < quizCount; i++) {
			 const auto& e = data[indices[i]];
			 questions.push_back({
		string(e.meaning) + "�̓ǂݕ����J�^�J�i�œ�����",
				 e.word });
		 }

		 break;
	 case 3: //�p�P��̈Ӗ��𓚂���
		 for (int i = 0; i < quizCount; i++) {
			 //�Ԉ�����ԍ��������_���ɑI��
			 const int correctIndex = indices[i];
			 vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			 //�����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			 const int correctNo = uniform_int_distribution<>(1, 3)(rd);
			 answers[correctNo - 1] = correctIndex;

			 //��蕶���쐬
			 string s = "�u" + string(data[correctIndex].word) +
				 "�v�̈Ӗ��Ƃ��Đ������ԍ���I��\n";
			 s += std::string(" 1:") + data[answers[0]].meaning + "\n";
			 s += std::string(" 2:") + data[answers[1]].meaning + "\n";
			 s += std::string(" 3:") + data[answers[2]].meaning + "\n";

			 questions.push_back({ s, to_string(correctNo) });
		 }
		 break;
	 }//swithe(type)
	 return questions;
}

//�p��̒�^���̖����쐬����
QuestionList  CreateEnglishPhraseExam()
{
	const struct {
		const char* phrase; //��^���̌`
		const char* meaning; //��^���̈Ӗ�
		const char* example; //�p��̗ᕶ
		const char* translation;//��ƂȂ���{���
		int blankCount;//���̌��̐�
		int blankOptions[3];//���̌��ɂȂ�P��̈ʒu
	}data[] = {
	{    "too[A]to[B]","�ƂĂ�[A]�Ȃ̂�[B]�f�L�i�C",
		 "The tea was too hot to drink.", "�������M�����Ĉ��߂Ȃ�����",
		 2,{3,5}},
		{"be Looking forward to [A]","[A]���y���݂ɂ���",
		 "I'm Looking forward to seening you", "���Ȃ��ɉ���Ƃ��y���݂ɂ��Ă��܂�",
		 3, {1,2,3}},
		{"according to [A]", "[A]�ɂ���",
		 "According to the weather forcast ,todey is rain. ","�V�C�\��ɂ��ƍ����͉J��",
		 2,{0,1}},
		{"as soon as[A]", "[A]����Ƃ�����",
		 "as soon as I arrive, I will call you.", "���������炷���ɓd�b���܂�",
		 3,{0,1,2}},
		{"be not supposed to [A]", "[A]���Ă͂����Ȃ����ƂɂȂ��Ă���",
		 "You are not supposed to enter this room.", "���̕����ɓ����Ă͍s���܂���",
		 3,{2,3,4}},
	};

	constexpr int quizCount = 26;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));
	random_device rd;

	//���̎�ނ������_���ɑI��
	int type = uniform_int_distribution<>(0, 2)(rd);
	switch (type) {
	case 0: //�󗓂ɓ���P��𓚂���
		for (int i = 0; i < quizCount; i++) {
			const auto& e = data[indices[i]];

		//�ᕶ��P��ɕ���
			vector<string> words;
			const char* start = e.example;
			for (const char* p = e.example; *p; p++) {
				if (*p == ' ') {
					words.push_back(string(start, p));
					start = p + 1;
				}
			}
			words.push_back(string(start));

			//���ɂ���P��̈ʒu��I��
			int n = uniform_int_distribution<>(0, e.blankCount - 1)(rd);
			int blankIndex = e.blankOptions[n];
			
			//���ɂ���ʒu�̒P��𓚂��Ƃ���
			string a = words[blankIndex];

			//���ɂ����̒P����󗓂ɏ���������
			words[blankIndex] = "[ ? ]";

			//�P������Ƃɕ���
			string s = words[0];
			for (int j = 1; j < words.size(); j++) {
				s += " " + words[j];
			}

			//��蕶�Ɠ�����ǉ�
			questions.push_back({
				"[?]�ɓK�؂Ȍ�����ĉp��������������\n" + string(e.translation) + "\n" + s,
				a });
		}
		break;

	case 1://��^���̈Ӗ��𓚂���
		for (int i = 0; i < quizCount; i++) {
			//�Ԉ�����ԍ��������_���ɑI��
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			//�����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			const int correctNo = uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			//��蕶���쐬
			string s = "�u" + string(data[correctIndex].meaning) +
				"�v�̈Ӗ��Ƃ��Đ������ԍ���I��\n";
			s += std::string(" 1:") + data[answers[0]].phrase + "\n";
			s += std::string(" 2:") + data[answers[1]].phrase + "\n";
			s += std::string(" 3:") + data[answers[2]].phrase;

			questions.push_back({ s, to_string(correctNo) });
		}
		break;

	case 2://�Ӗ��̍�����^���𓚂���
		for (int i = 0; i < quizCount; i++) {
			//�Ԉ�����ԍ��������_���ɑI��
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices(size(data), correctIndex);

			//�����_���Ȉʒu�𐳂����ԍ��ŏ㏑��
			const int correctNo = uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			//��蕶���쐬
			string s = "�u" + string(data[correctIndex].phrase) +
				"�v�ɑΉ������^����I��\n";
			s += std::string(" 1:") + data[answers[0]].meaning + "\n";
			s += std::string(" 2:") + data[answers[1]].meaning + "\n";
			s += std::string(" 3:") + data[answers[2]].meaning + "\n";

			questions.push_back({ s, to_string(correctNo) });
		}
		break;
	}//switch(type)

	return questions;
}