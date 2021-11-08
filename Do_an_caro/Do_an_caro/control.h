#ifndef _control_h_
#define _control_h_
void StartGame();
void ExitGame();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void Menu();
void Instruction();
void Infor();
void transFile(FILE* infile, FILE* outfile);
void Read(const char* filename);
void SaveGame();
void LoadGame(bool& ValidEnter);
#endif 


