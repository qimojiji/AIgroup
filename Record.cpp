#include "Record.h"


void Record::read()
{
	ifstream fin(filepath);
	if (!fin) {
		return ;
	}
	items.clear();
	int num = 0;
	fin >> num;
	for (int i = 0; i < num; i++) {
		string name_str;
		int the_score;
		fin >> name_str >> the_score;
		items.push_back(RecordItem(name_str, the_score));
		int idx = items.size() - 1;
		fin>>items[idx].speed;
		fin>>items[idx].ghost_num;
		fin>>items[idx].steps_num;
		int max_i = items[idx].steps_num;
		for (int i = 0; i < max_i; i++) {
			int temp;
			fin >> temp;
			items[idx].steps.push_back(temp);
		}
	}
	fin.close();
}
void Record::save()
{
	ofstream fout(filepath);
	if (!fout) {
		system("cls");
		
		cout << "same as exe file path��write\"" << filepath << "\"Read error! Please Change the file path...\n\n\n";

		exit(-1);
	}
	fout << items.size() << endl;
	for (auto& i_item : items) {
		fout << i_item.name << endl;
		fout << i_item.score << endl;
		fout << i_item.speed << endl;
		fout << i_item.ghost_num << endl;
		fout << i_item.steps_num << endl;
		for (int i = 0; i < i_item.steps_num; i++)
			fout << i_item.steps[i] << " ";
		fout << endl;
		fout << endl;
	}
	fout.close();
}

void Record::add(int the_score, const vector<int> &steps, int ghost_num, int speed)
{
	read();
	
	time_t t = time(NULL);
	char time_string[64] = { 0 };
	strftime(time_string, sizeof(time_string) - 1, "%Y-%m-%d_%H:%M:%S", localtime(&t));     //��-��-�� ʱ-��-��
	items.push_back(RecordItem(time_string, the_score));
	int idx = items.size() - 1;
	items[idx].ghost_num = ghost_num;
	items[idx].speed = speed;
	items[idx].steps_num = steps.size();
	for (auto istep : steps) {
		items[idx].steps.push_back(istep);
	}
	sort(items.begin(), items.end());
	if (items.size() > 10) {
		items.pop_back();
	}
	save();
}

void Record::del(int x)
{
	int counter = 0;
	for (auto i = items.begin(); i != items.end(); i++) {
		if (counter == x) {
			items.erase(i);
			save();
			return;
		}
		counter++;
	}
	return;
}


extern const int WINDOWS_SIZE_X;
extern const int WINDOWS_SIZE_Y;
void Record::show()
{
	
	int left_margin_No = WINDOWS_SIZE_X / 2 - 30;
	int left_margin_name = left_margin_No + 10;
	int left_margin_score = left_margin_name + 25;
	int left_margin_time = left_margin_score + 10;
	int left_margin_speed = left_margin_time + 12;
	int up_margin = 4;

	read();
	SetColor(WHITE_COLOR);
	system("cls");
	SetColor(HIGHLIGHT_COLOR);
	Goto_XY(WINDOWS_SIZE_X / 2 - 8, 0);
	cout << "HistoryRecord - TOP 10";
	SetColor(TITLE_COLOR);
	Goto_XY(left_margin_No, up_margin);
	cout << " Ranking";
	Goto_XY(left_margin_name, up_margin);
	cout << " RecordTime ";//��¼ʱ��
	Goto_XY(left_margin_score, up_margin);
	cout << " Score";
	Goto_XY(left_margin_time, up_margin);
	cout << " GameTime";
	Goto_XY(left_margin_speed, up_margin);
	cout << "MonsterSpeed";
	SetColor(WHITE_COLOR);

	if (items.size() == 0) {
		Goto_XY(left_margin_No, up_margin + 2);
		cout << "(Null Record)";
	}
	for (int i = 0; i < items.size(); i++) {
		Goto_XY(left_margin_No, up_margin + 2 + i * 2);
		cout << "No." << i + 1;
		Goto_XY(left_margin_name, up_margin + 2 + i * 2);
		cout << items[i].name;
		Goto_XY(left_margin_score, up_margin + 2 + i * 2);
		cout << items[i].score;
		Goto_XY(left_margin_time, up_margin + 2 + i * 2);
		printf("%.1fs", items[i].steps_num / (items[i].ghost_num + 1)*50.0 / 1000);
		Goto_XY(left_margin_speed, up_margin + 2 + i * 2);
		cout << items[i].speed<<" grid/s";
	}
	
}
