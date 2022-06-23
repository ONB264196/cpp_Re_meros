#pragma once

class GAME
{
	//�R���e�i
private:
	class CONTAINER* Container = nullptr;
public:
	class CONTAINER* container() { return Container; }
	//�V�[��
private:
	class TITLE* Title = nullptr;
	class STAGE* Stage = nullptr;
	class CLEAR* Clear = nullptr;
	class SCENE* CurScene = nullptr;
	class FADE* Fade = nullptr;	
public:
	class TITLE* title() { return Title; }
	class STAGE* stage() { return Stage; }
	class CLEAR* clear() { return Clear; }
	class FADE* fade() { return Fade; }
	void setCurScene(SCENE* scene);
	//�L�����N�^�[
private:
	class MAP* Map = nullptr;
	class CHARACTER_MANAGER* CharacterManager = nullptr;
	class PLAYER* Player = nullptr;
	class BOSS* Boss = nullptr;
	class RANK* Rank = nullptr;
public:
	class MAP* map() { return Map; }
	class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
	class PLAYER* player() { return Player; }
	class BOSS* boss() { return Boss; }
	class RANK* rank() { return Rank; }
public:
	GAME();
	~GAME();
	void run();
};
