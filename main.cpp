// ヘッダーファイル読み込み
#include "DxLib.h"
#include "resource.h"

//マクロ定義
#define GAME_WIDTH			1920	//画面の横の大きさ(800)
#define GAME_HEIGHT			1080	//画面の縦の大きさ(600)

#define GAME_WINDOW_BAR		0				//タイトルバーはデフォルト
#define GAME_WINDOW_NAME	"Sea Protecter"	//ウィンドウのタイトル

#define GAME_COLOR			32	//画面のカラービット
#define GAME_FPS			60	//FPSの数値	

//マウスのボタン
#define MOUSE_BUTTON_CODE	129	//0x0000～0x0080まで

//パスの長さ
#define PATH_MAX			255	//255文字まで
#define NAME_MAX			255	//255文字まで

//フォント
#define FONT_TANU_PATH			TEXT(".\\FONT\\TanukiMagic.ttf")	//フォントの場所
#define FONT_TANU_NAME			TEXT("たぬき油性マジック")			//フォントの名前

//エラーメッセージ
#define FONT_INSTALL_ERR_TITLE	TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE	TEXT("フォント作成エラー")

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")

//画像のパス
#define IMAGE_BACK_PATH			TEXT(".\\IMAGE\\Sea.jpg")		//背景の画像
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\イルカ.png")	//プレイヤーの画像
#define IMAGE_PLAYERBACK_PATH	TEXT(".\\IMAGE\\イルカ反転.png")//プレイヤー(反転)の画像

#define IMAGE_TITLE_BK_PATH			TEXT(".\\IMAGE\\タイトル海.jpg")	//タイトル背景の画像
#define IMAGE_TITLE_ROGO_PATH		TEXT(".\\IMAGE\\タイトルロゴ.png")	//タイトルロゴの画像
#define IMAGE_TITLE_ROGO_ROTA		0.005		//拡大率
#define IMAGE_TITLE_ROGO_ROTA_MAX	1.0			//拡大率MAX
#define IMAGE_TITLE_ROGO_X_SPEED	1			//X移動速度
#define IMAGE_TITLE_START_PATH		TEXT(".\\IMAGE\\クリックしてスタート画像.png")	//タイトルスタートの画像
#define IMAGE_TITLE_START_CNT		1			//点滅カウンタ(元は1)
#define IMAGE_TITLE_START_CNT_MAX	30			//点滅カウンタMAX(元は30)

#define IMAGE_STAGE_BUTTON_PATH		TEXT(".\\IMAGE\\ステージボタン.png")	//ステージ選択ボタンの画像
#define IMAGE_STAGE1_BUTTON_PATH	TEXT(".\\IMAGE\\ステージ１.png")		//ステージ１の画像
#define IMAGE_STAGE2_BUTTON_PATH	TEXT(".\\IMAGE\\ステージ２.png")		//ステージ２の画像
#define IMAGE_STAGE3_BUTTON_PATH	TEXT(".\\IMAGE\\ステージ３.png")		//ステージ２の画像
#define IMAGE_SETUP_BUTTON_PATH		TEXT(".\\IMAGE\\設定ボタン.png")		//ステージ選択ボタンの画像
#define IMAGE_RETURN_BUTTON_PATH	TEXT(".\\IMAGE\\リターンボタン.png")	//リターンボタンの画像
#define IMAGE_NEXT_BUTTON_PATH		TEXT(".\\IMAGE\\ネクストボタン.png")	//ネクストボタンの画像

#define IMAGE_END_COMP_PATH		TEXT(".\\IMAGE\\クリア！.png")	//エンドコンプ画像
#define IMAGE_END_COMP_CNT		1			//点滅カウンタ
#define IMAGE_END_COMP_CNT_MAX	30			//点滅カウンタMAX

#define IMAGE_END_FAIL_PATH		TEXT(".\\IMAGE\\mission_failed.png")	//エンドフォール画像
#define IMAGE_END_FAIL_CNT		1			//点滅カウンタ
#define IMAGE_END_FAIL_CNT_MAX	30			//点滅カウンタMAX

#define IMAGE_BACK_REV_PATH		TEXT(".\\IMAGE\\Sea.jpg")	//背景の画像
#define IMAGE_BACK_NUM			4							//背景の画像の数

//弾の設定
#define TAMA_CHANGE_MAX		 5	//5フレーム目で弾の画像を変える
#define TAMA_MAX			16	//最大16発まで

#define TAMA_RED_PATH			TEXT(".\\IMAGE\\TAMA\\red.png")		//赤弾の画像
#define TAMA_GREEN_PATH			TEXT(".\\IMAGE\\TAMA\\green.png")	//青弾の画像
#define TAMA_BLUE_PATH			TEXT(".\\IMAGE\\TAMA\\blue.png")	//緑弾の画像
#define TAMA_YELLOW_PATH		TEXT(".\\IMAGE\\TAMA\\yellow.png")	//黄弾の画像

#define TAMA_DIV_WIDTH		16	//画像を分割する幅サイズ
#define TAMA_DIV_HEIGHT		16	//画像を分割する高さサイズ

#define TAMA_DIV_TATE		3	//画像を縦に分割する数
#define TAMA_DIV_YOKO		1	//画像を横に分割する数

#define TAMA_DIV_NUM	TAMA_DIV_TATE * TAMA_DIV_YOKO	//画像を分割する総数

//エラーメッセージ
#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

//音楽のパス
#define MUSIC_BGM_PATH			TEXT(".\\MUSIC\\海賊達の海.mp3")			//BGM
#define MUSIC_PLAYER_SHOT_PATH	TEXT(".\\MUSIC\\ショット音.mp3")			//ショット音

#define MUSIC_CLICK_PATH		TEXT(".\\MUSIC\\決定、ボタン押下29.mp3")	//クリック音

#define MUSIC_BGM_TITLE_PATH	TEXT(".\\MUSIC\\周遊する銀鱗のひとつ.mp3")	//タイトルのBGM
#define MUSIC_BGM_MENU_PATH		TEXT(".\\MUSIC\\Good_Luck-よき旅を-.mp3")	//メニューのBGM
#define MUSIC_BGM_CHOICE_PATH	TEXT(".\\MUSIC\\レトロシューティング.mp3")	//ステージ選択画面のBGM
#define MUSIC_BGM_SETUP_PATH	TEXT(".\\MUSIC\\ウォータートンネル.mp3")	//設定のBGM
#define MUSIC_BGM_COMP_PATH		TEXT(".\\MUSIC\\ジングル素材07.mp3")		//コンプリートBGM
//#define MUSIC_BGM_FAIL_PATH	TEXT(".\\MUSIC\\衛星の夜.mp3")				//フォールトBGM
#define MUSIC_BGM_FAIL_PATH		TEXT(".\\MUSIC\\ジングル素材07.mp3")		//フォールトBGM(試験的に)

#define GAME_MAP_TATE_MAX	15	//マップの縦の数(もとは9)
#define GAME_MAP_YOKO_MAX	30	//マップの横の数(もとは13)
#define GAME_MAP_KIND_MAX	2	//マップの種類の数

#define GAME_MAP_PATH			TEXT(".\\IMAGE\\MAP\\map.png")		//マップの画像

#define MAP_DIV_WIDTH		64	//画像を分割する幅サイズ
#define MAP_DIV_HEIGHT		64	//画像を分割する高さサイズ
#define MAP_DIV_TATE		10	//画像を縦に分割する数
#define MAP_DIV_YOKO		4	//画像を横に分割する数
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//画像を分割する総数

//エラーメッセージ
#define START_ERR_TITLE		TEXT("スタート位置エラー")
#define START_ERR_CAPTION	TEXT("スタート位置が決まっていません")

#define GOAL_ERR_TITLE		TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION	TEXT("ゴール位置が決まっていません")

//終了ダイアログ用
#define MOUSE_R_CLICK_TITLE		TEXT("ゲーム中断")
#define MOUSE_R_CLICK_CAPTION	TEXT("ゲームを中断し、メニュー画面に戻りますか？")

#define KEY_END_TITLE			TEXT("ゲーム終了")
#define KEY_END_TITLE_CAPTION	TEXT("ゲームを終了しますか？")

enum GAME_MAP_KIND
{
	n = -1,	//(NONE)未定
	k = 0,	//壁
	t = 9,	//通路
	s = 5,	//スタート
	g = 3	//ゴール
};	//マップの種類

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_MENU,
	GAME_SCENE_CHOICE,
	GAME_SCENE_SETUP,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
	GAME_SCENE_CLEAR,
};	//ゲームのシーン

enum GAME_END {
	GAME_END_COMP,	//コンプリート
	GAME_END_FAIL	//フォールト
};	//ゲームの終了状態

enum CHARA_SPEED {
	CHARA_SPEED_LOW = 1,
	CHARA_SPEED_MIDI = 2,
	CHARA_SPEED_HIGH = 3
};	//キャラクターのスピード

enum CHARA_RELOAD {
	CHARA_RELOAD_LOW = 60,
	CHARA_RELOAD_MIDI = 30,
	CHARA_RELOAD_HIGH = 15
};	//キャラクターのリロード

//int型のPOINT構造体
typedef struct STRUCT_I_POINT
{
	int x = -1;	//座標を初期化
	int y = -1;	//座標を初期化
}iPOINT;

//マウス構造体
typedef struct STRUCT_MOUSE
{
	int InputValue = 0;	//GetMouseInputの値を入れる
	int WheelValue = 0;	//マウスホイールの回転量(奥はプラス値 / 手前はマイナス値)
	iPOINT Point;		//マウスの座標が入る
	iPOINT OldPoint;	//マウスの座標(直前)が入る
	int OldButton[MOUSE_BUTTON_CODE] = { 0 };	//マウスのボタン入力(直前)が入る
	int Button[MOUSE_BUTTON_CODE] = { 0 };	//マウスのボタン入力が入る
}MOUSE;

//フォント構造体
typedef struct STRUCT_FONT
{
	char path[PATH_MAX];		//パス
	char name[NAME_MAX];		//フォント名
	int handle;					//ハンドル
	int size;					//大きさ
	int bold;					//太さ
	int type;					//タイプ
	//※タイプは、https://dxlib.xsrv.jp/function/dxfunc_graph2.html#R17N10　を参照

}FONT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
	int x;						//X位置
	int y;						//Y位置
	int Lx;						//左位置(x位置)
	int Ly;						//左位置(y位置)
	int Rx;						//右位置(x位置)
	int Ry;						//右位置(y位置)
	int width;					//幅
	int height;					//高さ
}IMAGE;	//画像構造体

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル

	BOOL Check;					//チェッカー(追加)
}MUSIC;	//音楽構造体

typedef struct STRUCT_TAMA
{
	char path[PATH_MAX];				//パス
	int handle[TAMA_DIV_NUM];			//分割したの弾の画像ハンドルを取得
	int x;								//X位置
	int y;								//Y位置
	int width;							//幅
	int height;							//高さ
	BOOL IsDraw;						//弾を表示できるか
	int nowImageKind;					//弾の現在の画像
	int changeImageCnt;					//画像を変えるためのカウント
	int changeImageCntMAX;				//画像を変えるためのカウント(MAX)
	int speed;							//スピード
}TAMA;	//弾の構造体

typedef struct STRUCT_CHARA
{
	IMAGE image;				//IMAGE構造体
	int speed;					//速さ
	int CenterX;				//中心X
	int CenterY;				//中心Y

	MUSIC musicShot;			//プレイヤーの発射音

	BOOL CanShot;				//ショットできるか
	int ShotReLoadCnt;			//ショットリロード時間
	int ShotReLoadCntMAX;		//ショットリロード時間(MAX)

	TAMA tama[TAMA_MAX];		//ショットする弾

	RECT coll;					//当たり判定
	iPOINT collBeforePt;		//当たる前の座標

}CHARA;	//キャラクター構造体

typedef struct STRUCT_IMAGE_BACK
{
	IMAGE image;		//IMAGE構造体
	BOOL IsDraw;		//弾を表示できるか
}IMAGE_BACK;	//背景画像の構造体


typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;		//IMAGE構造体
	double angle;		//回転率
	double angleMAX;	//回転率MAX
	double rate;		//拡大率
	double rateMAX;		//拡大率MAX

}IMAGE_ROTA;	//回転拡大する画像の構造体

typedef struct STRUCT_IMAGE_BLINK
{
	IMAGE image;		//IMAGE構造体
	int Cnt;			//点滅カウンタ
	int CntMAX;			//点滅する時間MAX
	BOOL IsDraw;		//描画できるか？

}IMAGE_BLINK;	//点滅する画像の構造体

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//パス
	int handle[MAP_DIV_NUM];			//分割したの弾の画像ハンドルを取得
	int kind[MAP_DIV_NUM];				//マップの種類
	int width;							//幅
	int height;							//高さ
}MAPCHIP;	//MAP_IMAGE構造体

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//マップの種類
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
}MAP;	//MAP構造体

//グローバル変数
//FPS関連
int StartTimeFps;				//測定開始時刻
int CountFps;					//カウンタ
float CalcFps;					//計算結果
int SampleNumFps = GAME_FPS;	//平均を取るサンプル数

//キーボードの入力を取得
char AllKeyState[256] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[256] = { '\0' };	//すべてのキーの状態(直前)が入る

//マウスの座標を取得
MOUSE mouse;

FONT FontTanu32;	//たぬき油性マジック：大きさ32　のフォント構造体

int GameScene;		//ゲームシーンを管理
int StageNo;		//ステージナンバーを管理

int GameEndKind;					//ゲームの終了状態
RECT GoalRect = { -1,-1, -1, -1 };	//ゴールの当たり判定

IMAGE_BACK ImageBack[IMAGE_BACK_NUM];	//ゲームの背景

IMAGE ImageTitleBK;						//タイトル背景の画像
IMAGE_ROTA ImageTitleROGO;				//タイトルロゴの画像
IMAGE_BLINK ImageTitleSTART;			//タイトルスタートの画像

IMAGE ImageStartButton;					//ステージ選択ボタンの画像
IMAGE ImageSetupButton;					//設定ボタンの画像
IMAGE ImageStageButton1;				//ステージ１の画像
IMAGE ImageStageButton2;				//ステージ２の画像
IMAGE ImageStageButton3;				//ステージ２の画像
IMAGE ImageReturnButton;				//リターンボタンの画像
IMAGE ImageNextButton;					//ネクストボタンの画像

IMAGE_BLINK ImageEndCOMP;				//エンドコンプの画像
IMAGE_BLINK ImageEndFAIL;				//エンドフォールの画像

CHARA player;		//ゲームのキャラ
CHARA playerback;	//ゲームのキャラ

//音楽関連
MUSIC BGM;			//ゲームのBGM
MUSIC BGM_CLICK;	//クリック音

MUSIC BGM_TITLE;	//タイトルのBGM
MUSIC BGM_MENU;		//メニューのBGM
MUSIC BGM_CHOICE;	//ステージ選択画面のBGM
MUSIC BGM_SETUP;	//設定のBGM
MUSIC BGM_COMP;		//コンプリートのBGM
MUSIC BGM_FAIL;		//フォールトのBGM

GAME_MAP_KIND mapData[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]{
	//  0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,
		k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,	// 0
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 1
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 2
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 3
		t,t,t,t,t,t,t,t,t,g,t,t,t,t,t,t,t,t,t,s,t,t,t,t,t,t,t,t,t,t,	// 4
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 5
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 6
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 7
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 8
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 9
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 0
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 1
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 2
		t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 3
		//t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,	// 4
		k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,	// 5
};	//ゲームのマップ

//ゲームマップの初期化
GAME_MAP_KIND mapDataInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップチップの画像を管理
MAPCHIP mapChip;

//マップの場所を管理
MAP map[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//スタートの位置
iPOINT startPt{ -1,-1 };

//マップの当たり判定
RECT mapColl[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//プロトタイプ宣言
VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する
VOID MY_FPS_DRAW(VOID);				//FPS値を描画する
VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する
BOOL MY_KEYDOWN_KEEP(int, int);		//キーを押し続けているか、キーコードで判断する
BOOL MY_KEY_PUSH(int KEY_INPUT_);	//キーをプッシュしたか、キーコードで判断する

VOID MY_MOUSE_UPDATE(VOID);				//マウスの入力情報を更新する
BOOL MY_MOUSE_DOWN(int);				//ボタンを押しているか、マウスコードで判断する
BOOL MY_MOUSE_UP(int);					//ボタンを押し上げたか、マウスコードで判断する
BOOL MY_MOUSEDOWN_KEEP(int, int);		//ボタンを押し続けているか、マウスコードで判断する
BOOL MY_MOUSE_PUSH(int MOUSE_INPUT);	//ボタンをクリックしたか、マウスコードで判断する

BOOL MY_FONT_INSTALL_ONCE(VOID);	//フォントをこのソフト用に、一時的にインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID);	//フォントをこのソフト用に、一時的にアンインストール
BOOL MY_FONT_CREATE(VOID);			//フォントを作成する
VOID MY_FONT_DELETE(VOID);			//フォントを削除する

VOID MY_START(VOID);		//スタート画面
VOID MY_START_PROC(VOID);	//スタート画面の処理
VOID MY_START_DRAW(VOID);	//スタート画面の描画

VOID MY_MENU(VOID);			//メニュー画面
VOID MY_MENU_PROC(VOID);	//メニュー画面の処理
VOID MY_MENU_DRAW(VOID);	//メニュー画面の描画

VOID MY_CHOICE(VOID);		//ステージ選択画面
VOID MY_CHOICE_PROC(VOID);	//ステージ選択画面の処理
VOID MY_CHOICE_DRAW(VOID);	//ステージ選択画面の描画

VOID MY_SETUP(VOID);		//設定画面
VOID MY_SETUP_PROC(VOID);	//設定画面の処理
VOID MY_SETUP_DRAW(VOID);	//設定画面の描画

VOID MY_CLEAR(VOID);		//クリア画面
VOID MY_CLEAR_PROC(VOID);	//クリア画面の処理
VOID MY_CLEAR_DRAW(VOID);	//クリア画面の描画

VOID MY_PLAY(VOID);			//プレイ画面
VOID MY_PLAY_PROC(VOID);	//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);	//プレイ画面の描画

VOID MY_END(VOID);			//エンド画面
VOID MY_END_PROC(VOID);		//エンド画面の処理
VOID MY_END_DRAW(VOID);		//エンド画面の描画

BOOL MY_LOAD_IMAGE(VOID);		//画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);		//画像をまとめて削除する関数

BOOL MY_LOAD_MUSIC(VOID);		//音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);		//音楽をまとめて削除する関数

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//領域の当たり判定をする関数

//プログラムで最初に実行される関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);               //Log.txtを出力しない
	ChangeWindowMode(TRUE);								//全画面モードに設定(元に戻しました21日：ウィンドウモード)
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(GAME_WINDOW_BAR);				//タイトルバーはデフォルトにする
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//ウィンドウのタイトルの文字
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	SetWindowIconID(IDI_ICON1);							//アイコンファイルを読込

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	//カーソルのハンドルを取得
	HCURSOR cur_aim1 = LoadCursorFromFile(TEXT(IDC_CURSOR1));

	//ウィンドウクラスのカーソルのみ(GCL_HCURSOR)を変更する(Win32関数SetClassLong_Win64関数はSetClassLongPtr)
	LONG OldWindowClass
		= SetClassLongPtr(GetMainWindowHandle(), 0, (LONG)cur_aim1);

	//画像を読み込む
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//音楽を読み込む
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	//プレイヤーの設定
	player.CanShot = TRUE;
	player.ShotReLoadCnt = 0;
	player.ShotReLoadCntMAX = CHARA_RELOAD_HIGH;

	////BGMの設定(COMP・いらなかったので削除)
	//BGM_COMP.Check = TRUE;

	//フォントを一時的にインストール
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }
	//フォントハンドルを作成
	if (MY_FONT_CREATE() == FALSE) { return -1; }

	SetMouseDispFlag(TRUE);			//マウスカーソルを表示

	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から

	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	//プレイヤーの最初の位置を、スタート位置にする
	//ゴールの位置もついでに検索する
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//スタート位置を探す
			if (mapData[tate][yoko] == s)
			{
				//スタート位置を計算
				startPt.x = mapChip.width * yoko + mapChip.width / 2;	//中心X座標を取得
				startPt.y = mapChip.height * tate + mapChip.height / 2;	//中心Y座標を取得
			}

			//ゴール位置を探す
			if (mapData[tate][yoko] == g)
			{
				GoalRect.left = mapChip.width * yoko;
				GoalRect.top = mapChip.height * tate;
				GoalRect.right = mapChip.width * (yoko + 1);
				GoalRect.bottom = mapChip.height * (tate + 1);
			}
		}
	}

	//スタートが決まっていなければ
	if (startPt.x == -1 && startPt.y == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ゴールが決まっていなければ
	if (GoalRect.left == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了
		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		MY_ALL_KEYDOWN_UPDATE();				//押しているキー状態を取得

		MY_MOUSE_UPDATE();						//マウスの状態を取得

		MY_FPS_UPDATE();	//FPSの処理[更新]

		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//スタート画面
			break;
		case GAME_SCENE_MENU:
			MY_MENU();	//メニュー画面
			break;
		case GAME_SCENE_CHOICE:
			MY_CHOICE();//ステージ選択画面
			break;
		case GAME_SCENE_SETUP:
			MY_SETUP();	//設定画面
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;
		case GAME_SCENE_END:
			MY_END();	//エンド画面
			break;
		case GAME_SCENE_CLEAR:
			MY_CLEAR();	//クリアタイム画面
			break;
		}

		MY_FPS_DRAW();		//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}

	//フォントハンドルを破棄
	MY_FONT_DELETE();

	//一時的にインストールしたフォントをアンインストール
	MY_FONT_UNINSTALL_ONCE();

	//画像ハンドルを破棄
	MY_DELETE_IMAGE();

	//音楽ハンドルを破棄
	MY_DELETE_MUSIC();

	//ウィンドウクラスのカーソルのみ変更する(Win32関数ということは使えない？)
	SetClassLongPtr(GetMainWindowHandle(), 0, OldWindowClass);

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}

//FPS値を計測、更新する関数
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		//現在の時間から、0フレーム目の時間を引き、FPSの数値で割る＝1FPS辺りの平均時間が計算される
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//FPS値を描画する関数
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), "FPS:%.1f", CalcFps);
	return;
}

//FPS値を計測し、待つ関数
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//待つべき時間

	if (waitTime > 0)		//指定のFPS値よりも早い場合
	{
		WaitTimer(waitTime);	//待つ
	}
	return;
}

//キーの入力状態を更新する関数
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	//参考：https://dxlib.xsrv.jp/function/dxfunc_input.html

	char TempKey[256];	//一時的に、現在のキーの入力状態を格納する

	//直前のキー入力をとっておく
	for (int i = 0; i < 256; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//キーを押しているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}

//キーを押し上げたか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//直前は押していて
		&& AllKeyState[KEY_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//キーを押し上げている
	}
	else
	{
		return FALSE;	//キーを押し上げていない
	}
}

//キーを押し続けているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
//引　数：int：キーを押し続ける時間
BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{
	//押し続ける時間=秒数×FPS値
	//例）60FPSのゲームで、1秒間押し続けるなら、1秒×60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;	//押し続けている
	}
	else
	{
		return FALSE;	//押し続けていない
	}
}

//キーをプッシュしたか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_PUSH(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] == 0
		&& AllKeyState[KEY_INPUT_] >= 1)
	{
		return TRUE;	//キーをプッシュした(押し続けても１回のみ発生)
	}
	else
	{
		return FALSE;	//キーをプッシュしていないか押し続けている
	}
}


//マウスの入力情報を更新する
VOID MY_MOUSE_UPDATE(VOID)
{
	//マウスの以前の座標を取得
	mouse.OldPoint = mouse.Point;

	//マウスの以前のボタン入力を取得
	for (int i = 0; i < MOUSE_BUTTON_CODE; i++) { mouse.OldButton[i] = mouse.Button[i]; }

	//マウスの座標を取得
	GetMousePoint(&mouse.Point.x, &mouse.Point.y);

	//マウスの押しているボタンを取得
	mouse.InputValue = GetMouseInput();

	//左ボタンを押しているかチェック(TRUEは0以外なので、2も4もTRUE)
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }		//押している
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }		//押していない

	//中ボタンを押しているかチェック(TRUEは0以外なので、2も4もTRUE)
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//押している
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }	//押していない

	//右ボタンを押しているかチェック(TRUEは0以外なので、2も4もTRUE)
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }		//押している
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//押していない

	//ホイールの回転量を取得
	mouse.WheelValue = GetMouseWheelRotVol();

	return;
}

//ボタンを押しているか、マウスーコードで判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
BOOL MY_MOUSE_DOWN(int MOUSE_INPUT_)
{
	//マウスコードのボタンを押している時
	if (mouse.Button[MOUSE_INPUT_] != 0)
	{
		return TRUE;	//ボタンを押している
	}
	else
	{
		return FALSE;	//ボタンを押していない
	}
}

//ボタンを押し上げたか、マウスコード判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
BOOL MY_MOUSE_UP(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] >= 1	//直前は押していて
		&& mouse.Button[MOUSE_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//ボタンを押し上げている
	}
	else
	{
		return FALSE;	//ボタンを押し上げていない
	}
}

//ボタンを押し続けているか、マウスコード判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
//引　数：int：ボタンを押し続ける時間
BOOL MY_MOUSEDOWN_KEEP(int MOUSE_INPUT_, int DownTime)
{
	//押し続ける時間=秒数×FPS値
	//例）60FPSのゲームで、1秒間押し続けるなら、1秒×60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (mouse.Button[MOUSE_INPUT_] > UpdateTime)
	{
		return TRUE;	//押し続けている
	}
	else
	{
		return FALSE;	//押し続けていない
	}
}

//マウスをクリックしたか、キーコードで判断する
//引　数：int：マウスコード：MOUSE_INPUT_???
BOOL MY_MOUSE_PUSH(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] == 0	//押す前は0かつ
		&& mouse.Button[MOUSE_INPUT_] >= 1)	//現在押してるとき
	{
		return TRUE;	//キーをプッシュした(押し続けても１回のみ発生)
	}
	else
	{
		return FALSE;	//キーをプッシュしていないか押し続けている
	}
}

//フォントをこのソフト用に、一時的にインストール
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//フォントを一時的に読み込み(WinAPI)
	if (AddFontResourceEx(FONT_TANU_PATH, FR_PRIVATE, NULL) == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), FONT_TANU_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//フォントをこのソフト用に、一時的にアンインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//一時的に読み込んだフォントを削除(WinAPI)
	RemoveFontResourceEx(FONT_TANU_PATH, FR_PRIVATE, NULL);

	return;
}

//フォントを読み込む関数
//引　数：const char *：読み込むフォントの名前
//引　数：int　：フォントの大きさ
//引　数：int　：フォントの太さ
//引　数：int　：フォントのタイプ
//戻り値：なし→変更→戻り値：BOOL：エラー時：FALSE
BOOL MY_FONT_CREATE(VOID)
{
	//↓↓↓たぬき油性マジックのフォントを作成↓↓↓

	//フォントデータを作成
	strcpy_s(FontTanu32.path, sizeof(FontTanu32.path), FONT_TANU_PATH);	//パスをコピー
	strcpy_s(FontTanu32.name, sizeof(FontTanu32.name), FONT_TANU_NAME);	//フォント名をコピー
	FontTanu32.handle = -1;								//ハンドルを初期化
	FontTanu32.size = 32;								//サイズは32
	FontTanu32.bold = 1;								//太さ1
	FontTanu32.type = DX_FONTTYPE_ANTIALIASING_EDGE;	//アンチエイリアシング付きのフォント

	//フォントハンドル作成
	FontTanu32.handle = CreateFontToHandle(FontTanu32.name, FontTanu32.size, FontTanu32.bold, FontTanu32.type);
	//フォントハンドル作成できないとき、エラー
	if (FontTanu32.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_TANU_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	//↑↑↑たぬき油性マジックのフォントを作成↑↑↑

	return TRUE;
}

//フォントを削除する関数
VOID MY_FONT_DELETE(VOID)
{
	//フォントデータを削除
	DeleteFontToHandle(FontTanu32.handle);	//フォントのハンドルを削除

	return;
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();	//スタート画面の処理
	MY_START_DRAW();	//スタート画面の描画

	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//(変更,BGMの音量)
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 75 / 100, BGM_TITLE.handle);	//75%の音量にする
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	//左クリックしたら、メニューシーンへ移動する
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		////BGMが流れているなら(変更：止めない)
		//if (CheckSoundMem(BGM_TITLE.handle) != 0)
		//{
		//	StopSoundMem(BGM_TITLE.handle);	//BGMを止める
		//}

		//クリック音
		PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

		SetMouseDispFlag(TRUE);			//マウスカーソルを表示

		//プレイヤーの中心位置を計算する
		player.CenterX = startPt.x;
		player.CenterY = startPt.y;

		//プレイヤーの画像の位置を設定する
		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		//プレイヤー(反転)の画像の位置を設定する
		playerback.image.x = player.image.x;
		playerback.image.y = player.image.y;

		//プレイヤーの当たる以前の位置を設定する
		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;
		
		//(変更削除)
		/*
		//スタート位置をマウスの位置にする
		SetMousePoint(player.image.x, player.image.y);
		*/

		//弾を全て非表示にする(弾の表示バグ修正)
		for (int cnt = 0; cnt < TAMA_MAX; cnt++)
		{
			player.tama[cnt].IsDraw = FALSE;
		}

		//ゲームの終了状態を初期化する
		GameEndKind = GAME_END_FAIL;

		GameScene = GAME_SCENE_MENU;
	}

	////タイトルロゴを拡大
	//if (ImageTitleROGO.rate < ImageTitleROGO.rateMAX)
	//{
	//	ImageTitleROGO.rate += IMAGE_TITLE_ROGO_ROTA;
	//}

	////タイトルロゴを移動
	//if (ImageTitleROGO.image.x < GAME_WIDTH / 2)
	//{
	//	ImageTitleROGO.image.x += IMAGE_TITLE_ROGO_X_SPEED;
	//}

	////タイトルロゴを拡大---------------
	//if (ImageTitleROGO.rate < ImageTitleROGO.rateMAX)
	//{
	//	ImageTitleROGO.rate += IMAGE_TITLE_ROGO_ROTA;
	//}
	//else
	//{
	//	//タイトルロゴが拡大しきったら

	//	//スタートを点滅
	//	if (ImageTitleSTART.Cnt < ImageTitleSTART.CntMAX)
	//	{
	//		ImageTitleSTART.Cnt += IMAGE_TITLE_START_CNT;
	//	}
	//	else
	//	{
	//		//描画する/しないを決める
	//		if (ImageTitleSTART.IsDraw == FALSE)
	//		{
	//			ImageTitleSTART.IsDraw = TRUE;
	//		}
	//		else if (ImageTitleSTART.IsDraw == TRUE)
	//		{
	//			ImageTitleSTART.IsDraw = FALSE;
	//		}
	//		ImageTitleSTART.Cnt = 0;
	//	}

	//スタートを点滅(変更：ロゴが拡大しきったらの条件式がいらないかったので変更)
	if (ImageTitleSTART.Cnt < ImageTitleSTART.CntMAX)
	{
		ImageTitleSTART.Cnt += IMAGE_TITLE_START_CNT;
	}
	else
	{
		//描画する/しないを決める
		if (ImageTitleSTART.IsDraw == FALSE)
		{
			ImageTitleSTART.IsDraw = TRUE;
		}
		else if (ImageTitleSTART.IsDraw == TRUE)
		{
			ImageTitleSTART.IsDraw = FALSE;
		}
		ImageTitleSTART.Cnt = 0;

	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{

	//プログラム追加ここから
	/*
	//①画像の色を反転させる
	SetDrawBlendMode(DX_BLENDMODE_PMA_INVSRC, 255);

	//この次からの画像描画で、反転させる処理が反映される
	*/

	/*
	//②画像の色を半透明にさせる(透過度25%)
	double Percent = 25.0 / 100.0;	//透過度％
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Percent * 255);

	//この次からの画像描画で、半透明にさせる処理が反映される
	*/

	/*
	//③画像の色を明るくさせる
	//この画像↓の上から、明るくさせた画像を描画する
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	//明るくさせる処理×３回(※効果を実感するため３回処理しています)
	double Percent = 100.0 / 100.0;	//明るくする％
	SetDrawBlendMode(DX_BLENDMODE_ADD, Percent * 255);
	SetDrawBlendMode(DX_BLENDMODE_ADD, Percent * 255);
	SetDrawBlendMode(DX_BLENDMODE_ADD, Percent * 255);

	//この次からの画像描画で、明るくさせる処理が反映される
	*/

	/*
	//④画像の色を暗くさせる
	//この画像↓の上から、暗くさせた画像を描画する
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	//暗くさせる処理×３回(※効果を実感するため３回処理しています)
	double Percent = 80.0 / 100.0;	//暗くする％
	SetDrawBlendMode(DX_BLENDMODE_SUB, Percent * 255);
	SetDrawBlendMode(DX_BLENDMODE_SUB, Percent * 255);
	SetDrawBlendMode(DX_BLENDMODE_SUB, Percent * 255);

	//この次からの画像描画で、暗くさせる処理が反映される
	*/

	/*
	//⑤画像の輝度を赤色のみにする(Red,Green,Blue)
	SetDrawBright(255, 0, 0);

	//この次からの画像描画で、暗くさせる処理が反映される
	*/


	//背景を描画
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	/*
	//①画像の反転を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	*/

	/*
	//②画像の半透明を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	*/

	/*
	//③画像の明るさを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	*/

	/*
	//④画像の明るさを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	*/

	/*
	//⑤画像の輝度を元に戻す
	SetDrawBright(255, 255, 255);
	*/

	//タイトルロゴを回転しながら描画
	DrawRotaGraph(
		ImageTitleROGO.image.x, ImageTitleROGO.image.y,	//画像の座標
		ImageTitleROGO.rateMAX,							//画像の拡大率(rateからrateMAXに変更)
		ImageTitleROGO.angle,							//画像の回転率
		ImageTitleROGO.image.handle, TRUE);				//画像のハンドル

	//点滅
	if (ImageTitleSTART.IsDraw == TRUE)
	{
		//タイトルスタートの描画
		DrawGraph(ImageTitleSTART.image.x, ImageTitleSTART.image.y, ImageTitleSTART.image.handle, TRUE);
	}

	DrawString(0, 0, "スタート画面", GetColor(0, 0, 0));
	return;
}

//メニュー画面
VOID MY_MENU(VOID)
{
	MY_MENU_PROC();	//メニュー画面の処理
	MY_MENU_DRAW();	//メニュー画面の描画

	return;
}

//メニュー画面の処理
VOID MY_MENU_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//(変更,BGMの音量)
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 75 / 100, BGM_TITLE.handle);	//75%の音量にする
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	//左クリックしたら、ステージ選択シーンへ移動する
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		////BGMが流れているなら(変更：止めない)
		//if (CheckSoundMem(BGM_MENU.handle) != 0)
		//{
		//	StopSoundMem(BGM_MENU.handle);	//BGMを止める
		//}

		//ステージ選択ボタンを押したとき
		if (ImageStartButton.x <= mouse.Point.x &&							//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageStartButton.x + ImageStartButton.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageStartButton.y <= mouse.Point.y &&							//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageStartButton.y + ImageStartButton.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			GameScene = GAME_SCENE_CHOICE;
		}
	}

	//左クリック＋ボタンの位置なら、設定シーンへ移動する
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		////BGMが流れているなら(変更：止めない)
		//if (CheckSoundMem(BGM_MENU.handle) != 0)
		//{
		//	StopSoundMem(BGM_MENU.handle);	//BGMを止める
		//}

		//設定ボタンを押したとき
		if (ImageSetupButton.x <= mouse.Point.x &&							//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageSetupButton.x + ImageSetupButton.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageSetupButton.y <= mouse.Point.y &&							//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageSetupButton.y + ImageSetupButton.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			GameScene = GAME_SCENE_SETUP;
		}
	}

	return;
}

//メニュー画面の描画
VOID MY_MENU_DRAW(VOID)
{
	//背景を描画
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	//背景を描画
	DrawGraph(ImageStartButton.x, ImageStartButton.y, ImageStartButton.handle, TRUE);	//ステージ選択ボタンの描画

	//背景を描画
	DrawGraph(ImageSetupButton.x, ImageSetupButton.y, ImageSetupButton.handle, TRUE);	//設定ボタンの描画

	////タイトルロゴを描画
	//DrawGraph(ImageTitleROGO.image.x, ImageTitleROGO.image.y, ImageTitleROGO.image.handle, TRUE);	//画像の幅と高さを取得

	DrawRotaGraph(
		ImageTitleROGO.image.x, ImageTitleROGO.image.y,	//画像の座標
		ImageTitleROGO.rateMAX,							//画像の拡大率
		ImageTitleROGO.angle,							//画像の回転率
		ImageTitleROGO.image.handle, TRUE);				//画像のハンドル

	DrawString(0, 0, "メニュー画面", GetColor(0, 0, 0));
	return;
}

//ステージ選択画面
VOID MY_CHOICE(VOID)
{
	MY_CHOICE_PROC();	//ステージ選択画面の処理
	MY_CHOICE_DRAW();	//ステージ選択画面の描画

	return;
}

//ステージ選択画面の処理
VOID MY_CHOICE_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//(変更,BGMの音量)
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 75 / 100, BGM_TITLE.handle);	//75%の音量にする
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	//左クリックしたら、プレイシーンへ移動する
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		//ステージ１ボタンを押したとき
		if (ImageStageButton1.x <= mouse.Point.x &&								//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageStageButton1.x + ImageStageButton1.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageStageButton1.y <= mouse.Point.y &&								//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageStageButton1.y + ImageStageButton1.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			//BGMが流れているなら(変更：BGM_CHOICE→BGM_TITLE)
			if (CheckSoundMem(BGM_TITLE.handle) != 0)
			{
				StopSoundMem(BGM_TITLE.handle);	//BGMを止める
			}

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			StageNo = 1;	//ステージナンバー１にする

			GameScene = GAME_SCENE_PLAY;
		}

		//ステージ２ボタンを押したとき
		if (ImageStageButton2.x <= mouse.Point.x &&								//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageStageButton2.x + ImageStageButton2.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageStageButton2.y <= mouse.Point.y &&								//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageStageButton2.y + ImageStageButton2.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			//BGMが流れているなら(変更：BGM_CHOICE→BGM_TITLE)
			if (CheckSoundMem(BGM_TITLE.handle) != 0)
			{
				StopSoundMem(BGM_TITLE.handle);	//BGMを止める
			}

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			StageNo = 2;	//ステージナンバー２にする

			GameScene = GAME_SCENE_PLAY;
		}

		//ステージ３ボタンを押したとき
		if (ImageStageButton3.x <= mouse.Point.x &&								//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageStageButton3.x + ImageStageButton3.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageStageButton3.y <= mouse.Point.y &&								//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageStageButton3.y + ImageStageButton3.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			//BGMが流れているなら(変更：BGM_CHOICE→BGM_TITLE)
			if (CheckSoundMem(BGM_TITLE.handle) != 0)
			{
				StopSoundMem(BGM_TITLE.handle);	//BGMを止める
			}

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			StageNo = 3;	//ステージナンバー２にする

			GameScene = GAME_SCENE_PLAY;
		}

	}

	//左クリックしたら、メニューシーンへ戻る
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		//リターンボタンを押したとき
		if (ImageReturnButton.Lx <= mouse.Point.x &&							//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageReturnButton.Lx + ImageReturnButton.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageReturnButton.Ly <= mouse.Point.y &&							//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageReturnButton.Ly + ImageReturnButton.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			////BGMが流れているなら(変更：止めない)
			//if (CheckSoundMem(BGM_CHOICE.handle) != 0)
			//{
			//	StopSoundMem(BGM_CHOICE.handle);	//BGMを止める
			//}

			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			GameScene = GAME_SCENE_MENU;
		}
	}

	return;
}


//ステージ選択画面の描画
VOID MY_CHOICE_DRAW(VOID)
{
	//背景を描画
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	//背景を描画
	DrawGraph(ImageReturnButton.Lx, ImageReturnButton.Ly, ImageReturnButton.handle, TRUE);	//リターンボタンの描画

	//背景を描画
	DrawGraph(ImageStageButton1.x, ImageStageButton1.y, ImageStageButton1.handle, TRUE);	//ステージ１ボタンの描画

	//背景を描画
	DrawGraph(ImageStageButton2.x, ImageStageButton2.y, ImageStageButton2.handle, TRUE);	//ステージ２ボタンの描画

	//背景を描画
	DrawGraph(ImageStageButton3.x, ImageStageButton3.y, ImageStageButton3.handle, TRUE);	//ステージ３ボタンの描画

	////背景を描画
	//DrawGraph(ImageNextButton.x, ImageNextButton.y, ImageNextButton.handle, TRUE);			//ネクストボタンの描画

	DrawString(0, 0, "ステージ選択", GetColor(0, 0, 0));
	return;
}

//設定画面
VOID MY_SETUP(VOID)
{
	MY_SETUP_PROC();	//設定画面の処理
	MY_SETUP_DRAW();	//設定画面の描画

	return;
}

//設定画面の処理
VOID MY_SETUP_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//(変更,BGMの音量)
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 75 / 100, BGM_TITLE.handle);	//75%の音量にする
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}
	////右クリックしたらを押したら、メニューシーンへ移動する(戻る)
	//if (MY_MOUSE_PUSH(MOUSE_INPUT_RIGHT) == TRUE)
	//{
	//	//BGMが流れているなら(変更：止めない)
	//	if (CheckSoundMem(BGM_SETUP.handle) != 0)
	//	{
	//		StopSoundMem(BGM_SETUP.handle);	//BGMを止める
	//	}
	//}

	//左クリックしたら、メイン画面へ戻る
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		//リターンボタンを押したとき
		if (ImageReturnButton.x <= mouse.Point.x &&								//ボタン画像X(ボタン座標の最小値) <= マウス座標X
			mouse.Point.x <= ImageReturnButton.x + ImageReturnButton.width &&	//マウス座標X <= ボタン画像X(ボタン座標の最大値)
			ImageReturnButton.y <= mouse.Point.y &&								//ボタン画像Y(ボタン座標の最小値) <= マウス座標Y
			mouse.Point.y <= ImageReturnButton.y + ImageReturnButton.height)	//マウス座標Y <= ボタン画像Y(ボタン座標の最大値)
		{
			//クリック音
			PlaySoundMem(BGM_CLICK.handle, DX_PLAYTYPE_BACK);

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//ゲームの終了状態を初期化する
			GameEndKind = GAME_END_FAIL;

			GameScene = GAME_SCENE_MENU;
		}
	}

	return;
}


//設定画面の描画
VOID MY_SETUP_DRAW(VOID)
{
	//背景を描画
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画
	
	//背景を描画
	DrawGraph(ImageReturnButton.x, ImageReturnButton.y, ImageReturnButton.handle, TRUE);	//設定ボタンの描画

	DrawString(0, 0, "設定画面", GetColor(0, 0, 0));
	return;
}


//プレイ画面
VOID MY_PLAY(VOID)
{
	switch (StageNo)
	{
	case 1:
	{
		MY_PLAY_PROC();	//プレイ画面の処理
		MY_PLAY_DRAW();	//プレイ画面の描画
		break;
	}
	case 2:
	{
		MY_PLAY_PROC();	//プレイ画面の処理
		MY_PLAY_DRAW();	//プレイ画面の描画
		break;
	}
	case 3:
	{
		MY_PLAY_PROC();	//プレイ画面の処理
		MY_PLAY_DRAW();	//プレイ画面の描画
		break;
	}

	default:
		break;
	}

	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//マウスカーソルの座標を取得
	GetMousePoint(&mouse.Point.x, &mouse.Point.y);

	//BGMが流れていないなら
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * 50 / 100, BGM.handle);	//50%の音量にする

		//BGMを流す
		//DX_PLAYTYPE_NORMAL: ノーマル再生
		//DX_PLAYTYPE_BACK  : バックグラウンド再生
		//DX_PLAYTYPE_LOOP  : ループ再生
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}

	//マウスを右クリックすると、タイトル画面に戻る
	if (mouse.Button[MOUSE_INPUT_RIGHT] == TRUE)
	{
		//クリックした座標を取得しておく
		iPOINT R_ClickPt = mouse.Point;

		//マウスを表示
		SetMouseDispFlag(TRUE);

		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)		//YESなら、ゲームを中断する
		{
			//BGMが流れているなら
			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);	//BGMを止める
			}

			SetMouseDispFlag(TRUE);			//マウスカーソルを表示

			//強制的にメニュー画面に飛ぶ
			GameScene = GAME_SCENE_MENU;
			return;

		}
		else if (Ret == IDNO)	//NOなら、ゲームを続行する
		{
			//マウスの位置を、クリックする前に戻す
			SetMousePoint(R_ClickPt.x, R_ClickPt.y);

			//マウスを非表示にする。
			SetMouseDispFlag(TRUE);
		}
	}

	//マウスを勢いよく動かすと、壁抜けするバグが発生するため、キー操作に変更してもよい
	//[キー操作ここから](変更)
	player.speed = 2;
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE)
	{
		player.CenterY -= player.speed;
	}
	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
	{
		player.CenterY += player.speed;
	}
	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		player.CenterX -= player.speed;
	}
	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
	{
		player.CenterX += player.speed;
	}

	//(変更削除)
	//画面内にマウスがいれば
	/*if (mouse.Point.x >= 0 && mouse.Point.x <= GAME_WIDTH
		&& mouse.Point.y >= 0 && mouse.Point.y <= GAME_HEIGHT)
	{
		//マウスの当たる前の位置から、現在位置の差がこの数値以内なら、動ける
		int MoveValue = 100;

		//マウスの移動量が少ないときに、移動させる
		if (abs(player.collBeforePt.x - mouse.Point.x) < MoveValue
			&& abs(player.collBeforePt.y - mouse.Point.y) < MoveValue)
		{
			//プレイヤーの中心位置を設定する
			player.CenterX = mouse.Point.x;
			player.CenterY = mouse.Point.y;
		}
		else
		{
			//プレイヤーの中心位置を設定する
			player.CenterX = player.collBeforePt.x;
			player.CenterY = player.collBeforePt.y;

			//マウスの位置を設定する
			SetMousePoint(player.collBeforePt.x, player.collBeforePt.y);
		}

	}
	*/

	//プレイヤーの当たり判定の設定
	player.coll.left = player.CenterX - mapChip.width / 2 + 5;
	player.coll.top = player.CenterY - mapChip.height / 2 + 5;
	player.coll.right = player.CenterX + mapChip.width / 2 - 5;
	player.coll.bottom = player.CenterY + mapChip.height / 2 - 5;

	BOOL IsMove = TRUE;

	//プレイヤーとマップがあたっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player.coll) == TRUE)
	{
		//[キー操作ここから](変更)
		player.CenterX = player.collBeforePt.x;
		player.CenterY = player.collBeforePt.y;

		//(変更削除：マップにあたるたびマウスの位置が強制的に移動させられていたので削除)
		//SetMousePoint(player.collBeforePt.x, player.collBeforePt.y);
		IsMove = FALSE;
	}

	//画面にマウスがいればを削除(変更削除)
	/*
	if (IsMove == TRUE)
	{
		//画面内にマウスがいれば
		if (mouse.Point.x >= 0 && mouse.Point.x <= GAME_WIDTH
			&& mouse.Point.y >= 0 && mouse.Point.y <= GAME_HEIGHT)
		{
			//プレイヤーの位置に置き換える
			player.image.x = player.CenterX - player.image.width / 2;
			player.image.y = player.CenterY - player.image.height / 2;

			//あたっていないときの座標を取得
			player.collBeforePt.x = player.CenterX;
			player.collBeforePt.y = player.CenterY;
		}
	}
	*/

	if (IsMove == TRUE)
	{
		//プレイヤーの位置に置き換える
		player.image.x = player.CenterX - player.image.width / 2;
		player.image.y = player.CenterY - player.image.height / 2;

		//あたっていないときの座標を取得
		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;
	}

	//当たり判定が追いつかないので、画像の位置を当たり判定に使用する
	//当たり判定の領域は、画像よりも少し縮小する。縮小加減は、お好みで。
	//当たり判定の範囲が、画像の幅や高さよりも大きいと、バグるかも！？
	RECT PlayerRect;
	int CollRange = 5;	//当たり判定の範囲
	PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
	PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
	PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
	PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;

	//ゴールに触れているかチェック
	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGMを止める
		}

		SetMouseDispFlag(TRUE);			//マウスカーソルを表示

		GameEndKind = GAME_END_COMP;	//ミッションコンプリート！

		GameScene = GAME_SCENE_END;

		BGM_COMP.Check = TRUE;

		return;	//強制的にエンド画面に飛ぶ
	}

	//プレイヤーが画面外に出たら
	if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGMを止める
		}

		SetMouseDispFlag(TRUE);			//マウスカーソルを表示

		GameEndKind = GAME_END_FAIL;	//ミッションフォールト！

		GameScene = GAME_SCENE_END;		//エンド画面に移動

		BGM_FAIL.Check = TRUE;

		return;	//強制的にエンド画面に飛ぶ
	}

	//(変更削除)
	/*
	//マウスの左ボタンをクリックしたとき
	if (MY_MOUSE_DOWN(MOUSE_INPUT_LEFT) == TRUE)
	{
		//ショットが撃てるとき
		if (player.CanShot == TRUE)
		{
			//ショット発射！！
			PlaySoundMem(player.musicShot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;

			//空いているスロットで、弾の描画をする
			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama[cnt].IsDraw == FALSE)
				{
					//弾をY位置の中心から発射する(変更)
					//弾のX位置はプレイヤーの左部分から発射
					player.tama[cnt].x = player.image.x;

					//弾のY位置はプレイヤーの中心から発射
					player.tama[cnt].y = player.CenterY - player.tama[cnt].width / 2;

					////(変更削除)
					////弾のX位置はプレイヤーの中心から発射
					//player.tama[cnt].x = player.CenterX - player.tama[cnt].width / 2;

					////弾のY位置はプレイヤーの上部分から発射
					//player.tama[cnt].y = player.image.y;

					//弾を描画する
					player.tama[cnt].IsDraw = TRUE;

					break;
				}
			}
		}
	}
	*/

	//左クリックしたとき(変更：MY_MOUSE_DOWNとMOUSE_INPUT_LEFTに変更後、MY_MOUSE_PUSHに変更)
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)	//クリックしたとき
	{
		//ショットが撃てるとき
		if (player.CanShot == TRUE)
		{
			//ショット発射！！
			PlaySoundMem(player.musicShot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;

			//空いているスロットで、弾の描画をする
			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama[cnt].IsDraw == FALSE)
				{
					//弾をY位置の中心から発射する(変更)
					////弾のX位置はプレイヤーの左部分から発射
					//player.tama[cnt].x = player.image.x;

					//(変更：X位置の中心から発射)
					//弾のX位置はプレイヤーの左部分から発射
					player.tama[cnt].x = player.CenterX - player.tama[cnt].width / 2;

					//弾のY位置はプレイヤーの中心から発射
					player.tama[cnt].y = player.CenterY - player.tama[cnt].width / 2;

					//(変更削除)
					/*
					//弾のX位置はプレイヤーの中心から発射
					player.tama[cnt].x = player.CenterX - player.tama[cnt].width / 2;

					//弾のY位置はプレイヤーの上部分から発射
					player.tama[cnt].y = player.image.y;
					*/

					//弾を描画する
					player.tama[cnt].IsDraw = TRUE;

					break;
				}
			}
		}
	}

	//ショットが撃てないとき
	if (player.CanShot == FALSE)
	{
		//リロード時間が終わったとき
		if (player.ShotReLoadCnt == player.ShotReLoadCntMAX)
		{
			player.ShotReLoadCnt = 0;
			player.CanShot = TRUE;		//再びショットできる
		}

		player.ShotReLoadCnt++;	//リロードする
	}

	//背景画像を動かす
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		/*
		//画像を移動させる
		ImageBack[num].image.y++;
		*/

		//背景画像を描画できないとき
		if (ImageBack[num].IsDraw == FALSE)
		{
			//背景画像が画面内にいるとき
			if (ImageBack[num].image.y + ImageBack[num].image.height > 0)
			{
				ImageBack[num].IsDraw = TRUE;	//画像を描画する
			}
		}

		//背景画像が画面を通り越したとき
		if (ImageBack[num].image.y > GAME_HEIGHT)
		{
			ImageBack[num].image.y = 0 - ImageBack[0].image.height * 3;	//画像の高さ２つ分、上に移動させる
			ImageBack[num].IsDraw = FALSE;								//画像を描画しない
		}
	}
	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{
	//背景を描画する
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		//描画できるときは・・・
		if (ImageBack[num].IsDraw == TRUE)
		{
			//背景を描画
			DrawGraph(ImageBack[num].image.x, ImageBack[num].image.y, ImageBack[num].image.handle, TRUE);

			/*
			//背景画像の数字をテスト的に表示
			DrawFormatString(
				ImageBack[num].image.x,
				ImageBack[num].image.y,
				GetColor(255, 255, 255), "背景画像：%d", num + 1);
			*/
		}
	}

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップを描画
			DrawGraph(
				map[tate][yoko].x,
				map[tate][yoko].y,
				mapChip.handle[map[tate][yoko].kind],
				TRUE);
		}
	}

	/*(変更削除)
	//当たり判定の描画（デバッグ用）
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//壁ならば
			if (mapData[tate][yoko] == k)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			}

			//通路ならば
			if (mapData[tate][yoko] == t)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
			}
		}
	}
	*/
	
	//マウスの位置を表示(デバック用)
	DrawFormatString(150, 0, GetColor(255, 255, 255), "X座標：%d, Y座標：%d", mouse.Point.x, mouse.Point.y);

	//ゴールの描画（デバッグ用）
	DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);

	//プレイヤーを描画する(マウスの位置によって左向きと右向きを設定)
	if (mouse.Point.x < player.image.x)
	{
		DrawGraph(player.image.x, player.image.y, player.image.handle, TRUE);
	}
	else
	{
		DrawGraph(player.image.x, player.image.y, playerback.image.handle, TRUE);
	}
	

	//(変更削除)
	/*
	//当たり判定の描画（デバッグ用）
	DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);
	*/

	//弾の情報を生成
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		//描画できる弾の処理
		if (player.tama[cnt].IsDraw == TRUE)
		{
			//弾を描画する
			DrawGraph(
				player.tama[cnt].x,
				player.tama[cnt].y,
				player.tama[cnt].handle[player.tama[cnt].nowImageKind],	//現在の画像の種類にあったハンドル
				TRUE);

			//弾の表示フレームを増やす
			if (player.tama[cnt].changeImageCnt < player.tama[cnt].changeImageCntMAX)
			{
				player.tama[cnt].changeImageCnt++;
			}
			else
			{
				//現在表示している弾の種類が、まだあるとき
				if (player.tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)	//-1しないと、最後の種類のときに++されてしまう
				{
					player.tama[cnt].nowImageKind++;	//弾を次の種類にする
				}
				else
				{
					player.tama[cnt].nowImageKind = 0;	//弾の種類をリセットする
				}

				player.tama[cnt].changeImageCnt = 0;
			}

			if (mouse.Point.x < player.image.x)	//マウスのX位置がプレイヤーより小さいとき(変更：追加)
			{
				//弾を左に移動させる(変更)
				if (player.tama[cnt].x < 0)		//x座標が0より小さいときは描画しないってこと、違うなら弾移動させてる
				{
					player.tama[cnt].IsDraw = FALSE;	//描画終了
				}
				else
				{
					//player.tama[cnt].x -= player.tama[cnt].speed;(書き方を下のように変えました)
					player.tama[cnt].x = player.tama[cnt].x - player.tama[cnt].speed;	//弾を左に移動
				}
			}

			////弾を左に移動させる(変更)
			//if (player.tama[cnt].x < 0)//x座標が0より小さいときは描画しないってこと、違うなら弾移動させてる
			//{
			//	player.tama[cnt].IsDraw = FALSE;	//描画終了
			//}
			//else
			//{
			//	//player.tama[cnt].x -= player.tama[cnt].speed;(書き方を下のように変えました)
			//	player.tama[cnt].x = player.tama[cnt].x - player.tama[cnt].speed;
			//}

			////弾をマウスの位置に移動させる(変更)
			//if (player.tama[cnt].y < 0)
			//{
			//	player.tama[cnt].IsDraw = FALSE;	//描画終了
			//}
			//else
			//{
			//	player.tama[cnt].y -= player.tama[cnt].speed;
			//}

		}
	}

	return;
}

//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();	//エンド画面の処理
	MY_END_DRAW();	//エンド画面の描画
	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//左クリックしたら、クリアシーンへ移動する
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM_COMP.handle) != 0)
		{
			StopSoundMem(BGM_COMP.handle);	//BGMを止める
		}

		//BGMが流れているなら
		if (CheckSoundMem(BGM_FAIL.handle) != 0)
		{
			StopSoundMem(BGM_FAIL.handle);	//BGMを止める
		}

		SetMouseDispFlag(TRUE);		//マウスカーソルを表示

		GameScene = GAME_SCENE_CLEAR;

		return;
	}
	
	switch (GameEndKind)
	{
	case GAME_END_COMP:
		//コンプリートのとき

		if (BGM_COMP.Check == TRUE)
		{
			//BGMが流れていないなら
			if (CheckSoundMem(BGM_COMP.handle) == 0)
			{
				//BGMの音量を下げる
				ChangeVolumeSoundMem(255 * 50 / 100, BGM_COMP.handle);	//50%の音量にする
				PlaySoundMem(BGM_COMP.handle, DX_PLAYTYPE_BACK);		//音ファイルを再生する・NOMAL(ノーマル)再生で
				BGM_COMP.Check = FALSE;
			}
		}

		////BGMが流れていないなら
		//if (CheckSoundMem(BGM_COMP.handle) == 0)
		//{
		//	//BGMの音量を下げる
		//	ChangeVolumeSoundMem(255 * 50 / 100, BGM_COMP.handle);	//50%の音量にする
		//	PlaySoundMem(BGM_COMP.handle, DX_PLAYTYPE_BACK);		//音ファイルを再生する・NOMAL(ノーマル)再生で
		//}

		//コンプリートを点滅
		if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
		{
			ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
		}
		else
		{
			//描画する/しないを決める
			if (ImageEndCOMP.IsDraw == FALSE)
			{
				ImageEndCOMP.IsDraw = TRUE;
			}
			else if (ImageEndCOMP.IsDraw == TRUE)
			{
				ImageEndCOMP.IsDraw = FALSE;
			}
			ImageEndCOMP.Cnt = 0;
		}
		break;

	case GAME_END_FAIL:
		//フォールトのとき

		if (BGM_FAIL.Check == TRUE)
		{
			//BGMが流れていないなら
			if (CheckSoundMem(BGM_FAIL.handle) == 0)
			{
				//BGMの音量を下げる
				ChangeVolumeSoundMem(255 * 50 / 100, BGM_FAIL.handle);	//50%の音量にする
				PlaySoundMem(BGM_FAIL.handle, DX_PLAYTYPE_BACK);		//音ファイルを再生する・NOMAL(ノーマル)再生で
				BGM_FAIL.Check = FALSE;
			}
		}

		////BGMが流れていないなら
		//if (CheckSoundMem(BGM_FAIL.handle) == 0)
		//{
		//	//BGMの音量を下げる
		//	ChangeVolumeSoundMem(255 * 50 / 100, BGM_FAIL.handle);	//50%の音量にする
		//	PlaySoundMem(BGM_FAIL.handle, DX_PLAYTYPE_LOOP);		//音ファイルを再生する・LOOP(ループ)再生で
		//}

		//フォールトを点滅
		if (ImageEndFAIL.Cnt < ImageEndFAIL.CntMAX)
		{
			ImageEndFAIL.Cnt += IMAGE_END_FAIL_CNT;
		}
		else
		{
			//描画する/しないを決める
			if (ImageEndFAIL.IsDraw == FALSE)
			{
				ImageEndFAIL.IsDraw = TRUE;
			}
			else if (ImageEndFAIL.IsDraw == TRUE)
			{
				ImageEndFAIL.IsDraw = FALSE;
			}
			ImageEndFAIL.Cnt = 0;
		}
		break;
	}

	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	MY_PLAY_DRAW();	//プレイ画面を描画

	//ゲームの終了状態により、描画を変える
	switch (GameEndKind)
	{
	case GAME_END_COMP:
		//コンプリートのとき

		//点滅
		if (ImageEndCOMP.IsDraw == TRUE)
		{
			//コンプリートの描画
			DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);
		}
		break;

	case GAME_END_FAIL:
		//フォールトのとき

		//点滅
		if (ImageEndFAIL.IsDraw == TRUE)
		{
			//フォールトの描画
			DrawGraph(ImageEndFAIL.image.x, ImageEndFAIL.image.y, ImageEndFAIL.image.handle, TRUE);
		}
		break;

	}

	DrawString(0, 0, "エンド画面", GetColor(0, 0, 0));
	return;
}

//クリア画面
VOID MY_CLEAR(VOID)
{
	MY_CLEAR_PROC();	//クリア画面の処理
	MY_CLEAR_DRAW();	//クリア画面の描画

	return;
}

//クリア画面の処理
VOID MY_CLEAR_PROC(VOID)
{
	//エスケープキーが押されたとき終了
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE))
	{
		//終了ダイアログを表示
		int Ret = MessageBox(GetMainWindowHandle(), KEY_END_TITLE_CAPTION, KEY_END_TITLE, MB_YESNO);

		if (Ret == IDYES)	//YESなら、ゲームを中断する
		{
			DxLib_End();	//ＤＸライブラリ使用の終了処理
		}
	}

	//左クリックしたら、メニューシーンへ移動する
	if (MY_MOUSE_PUSH(MOUSE_INPUT_LEFT) == TRUE)
	{
		GameScene = GAME_SCENE_MENU;
	}

	return;
}

//クリア画面の描画
VOID MY_CLEAR_DRAW(VOID)
{
	//背景を描画
	DrawGraph(ImageBack[0].image.x, ImageBack[0].image.y, ImageBack[0].image.handle, TRUE);

	DrawString(0, 0, "クリア画面", GetColor(0, 0, 0));
	return;
}

//画像をまとめて読み込む関数
BOOL MY_LOAD_IMAGE(VOID)
{
	//タイトル背景
	strcpy_s(ImageTitleBK.path, IMAGE_TITLE_BK_PATH);			//パスの設定
	ImageTitleBK.handle = LoadGraph(ImageTitleBK.path);			//読み込み
	if (ImageTitleBK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleBK.handle, &ImageTitleBK.width, &ImageTitleBK.height);	//画像の幅と高さを取得
	ImageTitleBK.x = GAME_WIDTH / 2 - ImageTitleBK.width / 2;		//左右中央揃え
	ImageTitleBK.y = GAME_HEIGHT / 2 - ImageTitleBK.height / 2;		//上下中央揃え

	//タイトルロゴ
	strcpy_s(ImageTitleROGO.image.path, IMAGE_TITLE_ROGO_PATH);					//パスの設定
	ImageTitleROGO.image.handle = LoadGraph(ImageTitleROGO.image.path);			//読み込み
	if (ImageTitleROGO.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleROGO.image.handle, &ImageTitleROGO.image.width, &ImageTitleROGO.image.height);	//画像の幅と高さを取得
	//ImageTitleROGO.image.x = 230;							//光っている部分から描画したい
	ImageTitleROGO.image.y = GAME_HEIGHT / 2;				//中央寄せ(縦)
	ImageTitleROGO.image.x = GAME_WIDTH / 2;				//中央寄せ(横)
	ImageTitleROGO.angle = DX_PI * 2;						//回転率
	ImageTitleROGO.angleMAX = DX_PI * 2;					//回転率MAX
	ImageTitleROGO.rate = 0.0;								//拡大率
	ImageTitleROGO.rateMAX = IMAGE_TITLE_ROGO_ROTA_MAX;		//拡大率MAX

	//タイトルスタート
	strcpy_s(ImageTitleSTART.image.path, IMAGE_TITLE_START_PATH);					//パスの設定
	ImageTitleSTART.image.handle = LoadGraph(ImageTitleSTART.image.path);			//読み込み
	if (ImageTitleSTART.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_START_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleSTART.image.handle, &ImageTitleSTART.image.width, &ImageTitleSTART.image.height);	//画像の幅と高さを取得
	ImageTitleSTART.image.x = GAME_WIDTH / 2 - ImageTitleSTART.image.width / 2;			//左右中央揃え
	ImageTitleSTART.image.y = ImageTitleROGO.image.y + ImageTitleROGO.image.height / 2 + 10;	//ロゴの下に表示
	ImageTitleSTART.Cnt = 0.0;								//カウンタ
	ImageTitleSTART.CntMAX = IMAGE_TITLE_START_CNT_MAX;		//カウンタMAX
	ImageTitleSTART.IsDraw = FALSE;							//描画させない

	//ステージ選択ボタン
	strcpy_s(ImageStartButton.path, IMAGE_STAGE_BUTTON_PATH);			//パスの設定
	ImageStartButton.handle = LoadGraph(ImageStartButton.path);			//読み込み
	if (ImageStartButton.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_STAGE_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageStartButton.handle, &ImageStartButton.width, &ImageStartButton.height);	//画像の幅と高さを取得
	//ImageStartButton.x = GAME_WIDTH / 4 - ImageStartButton.width / 2;			//画面の左、1/4の場所に配置
	ImageStartButton.x = GAME_WIDTH / 4;										//画面の左、1/4の場所に配置(描画する基準点をボタンの左端からに変更)
	ImageStartButton.y = GAME_HEIGHT * 0.75 - ImageStartButton.height / 2;		//画面の下、1/4の場所に配置

	//ステージ１ボタン
	strcpy_s(ImageStageButton1.path, IMAGE_STAGE1_BUTTON_PATH);		//パスの設定
	ImageStageButton1.handle = LoadGraph(ImageStageButton1.path);	//読み込み
	if (ImageStageButton1.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_STAGE1_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageStageButton1.handle, &ImageStageButton1.width, &ImageStageButton1.height);	//画像の幅と高さを取得
	ImageStageButton1.x = GAME_WIDTH / 2 - ImageStageButton1.width / 2;		//画面中央に配置
	ImageStageButton1.y = GAME_HEIGHT /4 - ImageStageButton1.height / 2;	//画面の上、1/4の場所に配置

	//ステージ２ボタン
	strcpy_s(ImageStageButton2.path, IMAGE_STAGE2_BUTTON_PATH);		//パスの設定
	ImageStageButton2.handle = LoadGraph(ImageStageButton2.path);	//読み込み
	if (ImageStageButton2.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_STAGE2_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageStageButton2.handle, &ImageStageButton2.width, &ImageStageButton2.height);	//画像の幅と高さを取得
	ImageStageButton2.x = GAME_WIDTH / 2 - ImageStageButton2.width / 2;		//画面中央に配置
	ImageStageButton2.y = GAME_HEIGHT / 2 - ImageStageButton2.height / 2;	//画面中央に配置

	//ステージ３ボタン
	strcpy_s(ImageStageButton3.path, IMAGE_STAGE3_BUTTON_PATH);		//パスの設定
	ImageStageButton3.handle = LoadGraph(ImageStageButton3.path);	//読み込み
	if (ImageStageButton3.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_STAGE3_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageStageButton3.handle, &ImageStageButton3.width, &ImageStageButton3.height);	//画像の幅と高さを取得
	ImageStageButton3.x = GAME_WIDTH / 2 - ImageStageButton3.width / 2;			//画面中央に配置
	ImageStageButton3.y = GAME_HEIGHT * 0.75 - ImageStageButton3.height / 2;	//画面下4/1に配置

	//設定ボタン
	strcpy_s(ImageSetupButton.path, IMAGE_SETUP_BUTTON_PATH);			//パスの設定
	ImageSetupButton.handle = LoadGraph(ImageSetupButton.path);			//読み込み
	if (ImageSetupButton.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETUP_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageSetupButton.handle, &ImageSetupButton.width, &ImageSetupButton.height);	//画像の幅と高さを取得
	//ImageSetupButton.x = GAME_WIDTH * 0.75 - ImageSetupButton.width / 2;		//画面の左、1/4の場所に配置
	ImageSetupButton.x = GAME_WIDTH * 0.75 - ImageSetupButton.width;			//画面の左、1/4の場所に配置(描画する基準点ををボタンの右端からに変更)
	ImageSetupButton.y = GAME_HEIGHT *0.75 - ImageSetupButton.height / 2;		//画面の下、1/4の場所に配置

	//リターンボタン(戻る)
	strcpy_s(ImageReturnButton.path, IMAGE_RETURN_BUTTON_PATH);			//パスの設定
	ImageReturnButton.handle = LoadGraph(ImageReturnButton.path);		//読み込み
	if (ImageReturnButton.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_RETURN_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageReturnButton.handle, &ImageReturnButton.width, &ImageReturnButton.height);	//画像の幅と高さを取得
	//ImageReturnButton.x = GAME_WIDTH / 2 - ImageReturnButton.width / 2;			//画面の左、1/2の場所に配置(描画する基準点をボタンの中央からに変更)
	//ImageReturnButton.y = GAME_HEIGHT * 0.75 - ImageReturnButton.height / 2;	//画面の下、1/4の場所に配置
	//ImageReturnButton.Lx = GAME_WIDTH / 4;										//画面の左、1/4の場所に配置(描画する基準点をボタンの左端からに変更)
	//ImageReturnButton.Ly = GAME_HEIGHT * 0.75 - ImageStartButton.height / 2;	//画面の下、1/4の場所に配置
	//ImageReturnButton.Rx = GAME_WIDTH * 0.75 - ImageSetupButton.width;			//画面の左、1/4の場所に配置(描画する基準点ををボタンの右端からに変更)
	//ImageReturnButton.Ry = GAME_HEIGHT * 0.75 - ImageSetupButton.height / 2;	//画面の下、1/4の場所に配置

	ImageReturnButton.x = GAME_WIDTH / GAME_WIDTH;					//画面の左端に配置
	ImageReturnButton.y = GAME_HEIGHT - ImageReturnButton.height;	//画面の下端＋画像分上に配置
	ImageReturnButton.Lx = GAME_WIDTH / GAME_WIDTH;					//画面の左端に配置
	ImageReturnButton.Ly = GAME_HEIGHT - ImageReturnButton.height;	//画面の下端＋画像分上に配置
	ImageReturnButton.Rx = GAME_WIDTH / GAME_WIDTH;					//画面の左端に配置
	ImageReturnButton.Ry = GAME_HEIGHT - ImageReturnButton.height;	//画面の下端＋画像分上に配置

	//ネクストボタン(次へ進む)
	strcpy_s(ImageNextButton.path, IMAGE_NEXT_BUTTON_PATH);			//パスの設定
	ImageNextButton.handle = LoadGraph(ImageNextButton.path);		//読み込み
	if (ImageNextButton.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_NEXT_BUTTON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageNextButton.handle, &ImageNextButton.width, &ImageNextButton.height);	//画像の幅と高さを取得
	ImageNextButton.x = GAME_WIDTH * 0.75 - ImageSetupButton.width;			//画面の左、1/4の場所に配置(描画する基準点ををボタンの右端からに変更)
	ImageNextButton.y = GAME_HEIGHT * 0.75 - ImageSetupButton.height / 2;	//画面の下、1/4の場所に配置

	//エンドコンプ
	strcpy_s(ImageEndCOMP.image.path, IMAGE_END_COMP_PATH);					//パスの設定
	ImageEndCOMP.image.handle = LoadGraph(ImageEndCOMP.image.path);			//読み込み
	if (ImageEndCOMP.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndCOMP.image.handle, &ImageEndCOMP.image.width, &ImageEndCOMP.image.height);	//画像の幅と高さを取得
	ImageEndCOMP.image.x = GAME_WIDTH / 2 - ImageEndCOMP.image.width / 2;			//左右中央揃え
	ImageEndCOMP.image.y = GAME_HEIGHT / 2 - ImageEndCOMP.image.height / 2;			//上下中央揃え
	ImageEndCOMP.Cnt = 0.0;									//カウンタ
	ImageEndCOMP.CntMAX = IMAGE_END_COMP_CNT_MAX;			//カウンタMAX
	ImageEndCOMP.IsDraw = FALSE;							//描画させない

	//エンドフォール
	strcpy_s(ImageEndFAIL.image.path, IMAGE_END_FAIL_PATH);				//パスの設定
	ImageEndFAIL.image.handle = LoadGraph(ImageEndFAIL.image.path);			//読み込み
	if (ImageEndFAIL.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_FAIL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndFAIL.image.handle, &ImageEndFAIL.image.width, &ImageEndFAIL.image.height);	//画像の幅と高さを取得
	ImageEndFAIL.image.x = GAME_WIDTH / 2 - ImageEndFAIL.image.width / 2;			//左右中央揃え
	ImageEndFAIL.image.y = GAME_HEIGHT / 2 - ImageEndFAIL.image.height / 2;			//上下中央揃え
	ImageEndFAIL.Cnt = 0.0;									//カウンタ
	ImageEndFAIL.CntMAX = IMAGE_END_FAIL_CNT_MAX;			//カウンタMAX
	ImageEndFAIL.IsDraw = FALSE;							//描画させない

	//背景画像
	strcpy_s(ImageBack[0].image.path, IMAGE_BACK_PATH);			//パスの設定
	strcpy_s(ImageBack[1].image.path, IMAGE_BACK_REV_PATH);		//パスの設定(背景画像反転)
	strcpy_s(ImageBack[2].image.path, IMAGE_BACK_PATH);			//パスの設定
	strcpy_s(ImageBack[3].image.path, IMAGE_BACK_REV_PATH);		//パスの設定(背景画像反転)

	//画像を連続して読み込み
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		ImageBack[num].image.handle = LoadGraph(ImageBack[num].image.path);	//読み込み
		if (ImageBack[num].image.handle == -1)
		{
			//エラーメッセージ表示
			MessageBox(GetMainWindowHandle(), IMAGE_BACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
		//画像の幅と高さを取得
		GetGraphSize(ImageBack[num].image.handle, &ImageBack[num].image.width, &ImageBack[num].image.height);
	}
	//背景画像①の設定
	ImageBack[0].image.x = GAME_WIDTH / 2 - ImageBack[0].image.width / 2;	//左右中央揃え
	ImageBack[0].image.y = 0 - ImageBack[0].image.height * 0;				//yは原点から
	ImageBack[0].IsDraw = FALSE;

	//背景画像②の設定
	ImageBack[1].image.x = GAME_WIDTH / 2 - ImageBack[1].image.width / 2;	//左右中央揃え
	ImageBack[1].image.y = 0 - ImageBack[0].image.height * 1;				//画像の高さ１つ分、上に移動させる
	ImageBack[1].IsDraw = FALSE;

	//背景画像③の設定
	ImageBack[2].image.x = GAME_WIDTH / 2 - ImageBack[2].image.width / 2;	//左右中央揃え
	ImageBack[2].image.y = 0 - ImageBack[0].image.height * 2;				//画像の高さ２つ分、上に移動させる
	ImageBack[2].IsDraw = FALSE;

	//背景画像③の設定
	ImageBack[3].image.x = GAME_WIDTH / 2 - ImageBack[2].image.width / 2;	//左右中央揃え
	ImageBack[3].image.y = 0 - ImageBack[0].image.height * 3;				//画像の高さ３つ分、上に移動させる
	ImageBack[3].IsDraw = FALSE;

	//プレイヤーの画像
	strcpy_s(player.image.path, IMAGE_PLAYER_PATH);		//パスの設定
	player.image.handle = LoadGraph(player.image.path);	//読み込み
	if (player.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(player.image.handle, &player.image.width, &player.image.height);	//画像の幅と高さを取得
	player.image.x = GAME_WIDTH / 2 - player.image.width / 2;		//左右中央揃え
	player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;		//上下中央揃え
	player.CenterX = player.image.x + player.image.width / 2;		//画像の横の中心を探す
	player.CenterY = player.image.y + player.image.height / 2;		//画像の縦の中心を探す
	player.speed = CHARA_SPEED_HIGH;								//スピードを設定

	//赤弾の画像を分割する
	int tamaRedRes = LoadDivGraph(
		TAMA_RED_PATH,										//赤弾のパス
		TAMA_DIV_NUM, TAMA_DIV_TATE, TAMA_DIV_YOKO,			//赤弾を分割する数
		TAMA_DIV_WIDTH, TAMA_DIV_HEIGHT,					//画像を分割するの幅と高さ
		&player.tama[0].handle[0]);							//分割した画像が入るハンドル

	//プレイヤー(反転)の画像
	strcpy_s(playerback.image.path, IMAGE_PLAYERBACK_PATH);		//パスの設定
	playerback.image.handle= LoadGraph(playerback.image.path);	//読み込み
	if (playerback.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYERBACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(playerback.image.handle, &playerback.image.width, &playerback.image.height);	//画像の幅と高さを取得
	playerback.image.x = GAME_WIDTH / 2 - playerback.image.width / 2;		//左右中央揃え
	playerback.image.y = GAME_HEIGHT / 2 - playerback.image.height / 2;		//上下中央揃え

	if (tamaRedRes == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), TAMA_RED_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(player.tama[0].handle[0], &player.tama[0].width, &player.tama[0].height);

	//弾の情報を生成
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		//パスをコピー
		strcpyDx(player.tama[cnt].path, TEXT(TAMA_RED_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			//ハンドルをコピー
			player.tama[cnt].handle[i_num] = player.tama[0].handle[i_num];
		}

		//幅をコピー
		player.tama[cnt].width = player.tama[0].width;

		//高さをコピー
		player.tama[cnt].height = player.tama[0].height;

		//弾のX位置はプレイヤーの中心から発射
		player.tama[cnt].x = player.CenterX - player.tama[cnt].width / 2;

		//弾のY位置はプレイヤーの上部分から発射
		player.tama[cnt].y = player.image.y;

		//弾は最初は非表示
		player.tama[cnt].IsDraw = FALSE;

		//弾の表示カウントを0にする
		player.tama[cnt].changeImageCnt = 0;

		//弾の表示カウントMAXを設定する
		player.tama[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		//現在の画像の種類を初期化する
		player.tama[cnt].nowImageKind = 0;

		//弾のスピードを設定する(変更)
		player.tama[cnt].speed = CHARA_SPEED_HIGH;
	}

	//マップの画像を分割する
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//赤弾のパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//赤弾を分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip.handle[0]);								//分割した画像が入るハンドル

	if (mapRes == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit[tate][yoko] = mapData[tate][yoko];

			//マップの種類をコピー
			map[tate][yoko].kind = mapData[tate][yoko];

			//マップの幅と高さをコピー
			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}

	//マップの当たり判定を設定する
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップの当たり判定を設定
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;
		}
	}

	return TRUE;
}

//画像をまとめて削除する関数
VOID MY_DELETE_IMAGE(VOID)
{
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		DeleteGraph(ImageBack[0].image.handle);
	}

	DeleteGraph(player.image.handle);
	DeleteGraph(playerback.image.handle);

	DeleteGraph(ImageTitleBK.handle);
	DeleteGraph(ImageTitleROGO.image.handle);
	DeleteGraph(ImageTitleSTART.image.handle);
	DeleteGraph(ImageStartButton.handle);
	DeleteGraph(ImageStageButton1.handle);
	DeleteGraph(ImageStageButton2.handle);
	DeleteGraph(ImageStageButton3.handle);
	DeleteGraph(ImageSetupButton.handle);
	DeleteGraph(ImageReturnButton.handle);
	DeleteGraph(ImageNextButton.handle);
	DeleteGraph(ImageEndCOMP.image.handle);
	DeleteGraph(ImageEndFAIL.image.handle);

	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player.tama[0].handle[i_num]); }

	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }

	return;
}

//音楽をまとめて読み込む関数
BOOL MY_LOAD_MUSIC(VOID)
{
	//背景音楽
	strcpy_s(BGM.path, MUSIC_BGM_PATH);		//パスの設定
	BGM.handle = LoadSoundMem(BGM.path);	//読み込み
	if (BGM.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//プレイヤーのショット音
	strcpy_s(player.musicShot.path, MUSIC_PLAYER_SHOT_PATH);			//パスの設定
	player.musicShot.handle = LoadSoundMem(player.musicShot.path);		//読み込み
	if (player.musicShot.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_PLAYER_SHOT_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//クリック音
	strcpy_s(BGM_CLICK.path, MUSIC_CLICK_PATH);				//パスの設定
	BGM_CLICK.handle = LoadSoundMem(BGM_CLICK.path);		//読み込み
	if (BGM_CLICK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_CLICK_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//タイトルのBGM
	strcpy_s(BGM_TITLE.path, MUSIC_BGM_TITLE_PATH);				//パスの設定
	BGM_TITLE.handle = LoadSoundMem(BGM_TITLE.path);			//読み込み
	if (BGM_TITLE.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_TITLE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	////メニューのBGM(変更：使う場面が無かった)
	//strcpy_s(BGM_MENU.path, MUSIC_BGM_MENU_PATH);				//パスの設定
	//BGM_MENU.handle = LoadSoundMem(BGM_MENU.path);				//読み込み
	//if (BGM_MENU.handle == -1)
	//{
	//	//エラーメッセージ表示
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_MENU_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////ステージ選択画面のBGM
	//strcpy_s(BGM_CHOICE.path, MUSIC_BGM_CHOICE_PATH);			//パスの設定
	//BGM_CHOICE.handle = LoadSoundMem(BGM_CHOICE.path);			//読み込み
	//if (BGM_CHOICE.handle == -1)
	//{
	//	//エラーメッセージ表示
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_CHOICE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}

	////設定のBGM
	//strcpy_s(BGM_SETUP.path, MUSIC_BGM_SETUP_PATH);				//パスの設定
	//BGM_SETUP.handle = LoadSoundMem(BGM_SETUP.path);				//読み込み
	//if (BGM_SETUP.handle == -1)
	//{
	//	//エラーメッセージ表示
	//	MessageBox(GetMainWindowHandle(), MUSIC_BGM_SETUP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}


	//コンプリートBGM
	strcpy_s(BGM_COMP.path, MUSIC_BGM_COMP_PATH);				//パスの設定
	BGM_COMP.handle = LoadSoundMem(BGM_COMP.path);				//読み込み
	if (BGM_COMP.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//フォールトのBGM
	strcpy_s(BGM_FAIL.path, MUSIC_BGM_FAIL_PATH);				//パスの設定
	BGM_FAIL.handle = LoadSoundMem(BGM_FAIL.path);				//読み込み
	if (BGM_FAIL.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_FAIL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//音楽をまとめて削除する関数
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);
	DeleteSoundMem(player.musicShot.handle);
	DeleteSoundMem(BGM_CLICK.handle);
	DeleteSoundMem(BGM_TITLE.handle);
	DeleteSoundMem(BGM_COMP.handle);
	DeleteSoundMem(BGM_FAIL.handle);

	return;
}

//マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//マップの当たり判定を設定する
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				//壁のときは、プレイヤーとマップが当たっている
				if (map[tate][yoko].kind == k) { return TRUE; }
			}
		}
	}

	return FALSE;
}

//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}
