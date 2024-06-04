#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include<conio.h>
#include <random>
#include <time.h>
#include<windows.h>

using namespace std;
int H, A, B, C, D, S, count_role, site, money, H_now, M, M_now, LV, LV_total, monster_Hp_now, fake_A, fake_B, fake_C, fire, ice, miss, fake_S, curse, role_count;
string acc, name, role_type;
string armor, arms;
string arms_bag[8] = { "普通長劍(戰士)","暴風大劍(戰士)","爆裂魔杖(法師)","巨型魔棒(法師)","反曲大弓(射手)","衝擊火炮(射手)","天使之杖(牧師)","時光之杖(牧師)" };
string arms_role[8] = { "戰士","戰士","法師","法師","射手","射手","牧師","牧師" };
int arms_value[8] = { 10,40,40,60,25,35,60,60 };
int arms_bag_count[8] = { 0 };
int account_arms_bag_count[8] = { 0 };
string armor_bag[5] = { "自然之力","死者肩甲","荊棘之甲","好戰者鎧甲","振奮盔甲" };
int armor_value[5] = { 350,300,350,800,450 };
int armor_bag_count[5] = { 0 };
int account_armor_bag_count[5] = { 0 };
string food_bag[5] = { "生命藥水","污濁藥劑","抗擊藥劑","巫魔藥劑","憤怒藥劑" };
int food_bag_count[5] = { 0 };
int account_food_bag_count[5] = { 0 };
string item[2] = { "無","無" };
string monster_name[8] = { "河蟹","啾吉","野狼","六鳥","石像","火蜥","飛龍","巴隆" };
string battle_name[5] = { "","","","","" };
int monster_value[5][7] = { 0 };
string skill_list[4] = { "","","","" };
int LV_need[21] = { 0,10,30,60,100,150,210,280,360,450,550,660,780,910,1050,1200,1360,1530,1710,1900,2100 };
string all_role[3][2];
int all_able[3][9];
int arms_bag_count2[3][8] = { 0 };
int armor_bag_count2[3][5] = { 0 };
int food_bag_count2[3][5] = { 0 };
string item_count2[3][2] = { {"無","無"},{"無","無"},{"無","無"} };

//輸入任意字繼續
string enter_type(int x)
{
    cout << endl;
    cout << "請輸入任意字到下一步" << endl;
    string AA;
    cin >> AA;
    return AA;
}
//存檔
int saving(int x)
{
    ifstream saving1;
    ofstream saving2;
    ifstream account_save;
    ofstream account_save2;
    saving1.open("player.txt");
    saving2.open("player2.txt");
    account_save.open("accountbox.txt");
    account_save2.open("accountbox2.txt");
    string pac, pname;

    while (saving1 >> pac)
    {
        saving1 >> pname;
        if (pac != acc || pname != name)
        {
            saving2 << pac << endl << pname << endl;
            for (int i = 0; i < 2; i++)
            {
                saving1 >> pac;
                saving2 << pac << " ";
            }
            saving2 << endl;
            for (int i = 0; i < 7; i++)
            {
                saving1 >> pac;
                saving2 << pac << endl;

            }
            for (int i = 0; i < 8; i++)
            {
                saving1 >> pac;
                saving2 << pac << " ";
            }
            saving2 << endl;
            for (int i = 0; i < 5; i++)
            {
                saving1 >> pac;
                saving2 << pac << " ";
            }
            saving2 << endl;
            for (int i = 0; i < 5; i++)
            {
                saving1 >> pac;
                saving2 << pac << " ";
            }
            saving2 << endl;
            for (int i = 0; i < 2; i++)
            {
                saving1 >> pac;
                saving2 << pac << " ";
            }
            saving2 << endl;
            saving1 >> pac;
            saving2 << pac << endl;
        }
        else
        {
            for (int i = 0; i < 30; i++)
            {
                saving1 >> pac;
            }
        }
    }
    string account_ac;
    while (account_save >> account_ac)
    {
        if (account_ac != acc)
        {
            account_save2 << account_ac << endl;
            for (int i = 0; i < 8; i++)
            {
                account_save >> account_ac;
                account_save2 << account_ac << " ";
            }
            account_save2 << endl;
            for (int i = 0; i < 5; i++)
            {
                account_save >> account_ac;
                account_save2 << account_ac << " ";
            }
            account_save2 << endl;
            for (int i = 0; i < 5; i++)
            {
                account_save >> account_ac;
                account_save2 << account_ac << " ";
            }
            account_save2 << endl;
        }
        else
        {
            for (int i = 0; i < 18; i++)
            {
                account_save >> account_ac;
            }
        }
    }
    account_save2 << acc << endl;
    for (int i = 0; i < 8; i++)
    {
        account_save2 << account_arms_bag_count[i] << " ";
    }
    account_save2 << endl;
    for (int i = 0; i < 5; i++)
    {
        account_save2 << account_armor_bag_count[i] << " ";
    }
    account_save2 << endl;
    for (int i = 0; i < 5; i++)
    {
        account_save2 << account_food_bag_count[i] << " ";
    }
    account_save2 << endl;
    saving2 << acc << endl << name << endl << role_type << " " << LV << endl << H << endl << A << endl << B << endl << C << endl << D << endl << S << endl << money << endl;
    for (int i = 0; i < 8; i++)
    {
        saving2 << arms_bag_count[i] << " ";
    }
    saving2 << endl;
    for (int i = 0; i < 5; i++)
    {
        saving2 << armor_bag_count[i] << " ";
    }
    saving2 << endl;
    for (int i = 0; i < 5; i++)
    {
        saving2 << food_bag_count[i] << " ";
    }
    saving2 << endl;
    for (int i = 0; i < 2; i++)
    {
        saving2 << item[i] << " ";
    }
    saving2 << endl;
    saving2 << LV_total;
    saving2 << endl;
    account_save.close();
    account_save2.close();
    saving1.close();
    saving2.close();
    remove("player.txt");
    rename("player2.txt", "player.txt");
    remove("accountbox.txt");
    rename("accountbox2.txt", "accountbox.txt");
    cout << "\n存檔成功" << endl << endl;
    return 0;
}
//角色屬性欄
int role_list(int x)
{
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "名稱:" << name << endl;
    cout << "職業:" << role_type << " " << LV << "等(" << LV_total << "/" << LV_need[LV] << ")" << endl;
    cout << "血量:" << H_now << " / " << H << endl;
    cout << "魔力:" << M_now << " / " << M << endl;
    cout << "物攻:" << A << endl;
    cout << "魔攻:" << B << endl;
    cout << "物防:" << C << endl;
    cout << "魔防:" << D << endl;
    cout << "速度:" << S << endl;
    cout << "現有金錢:" << money << endl;
    cout << "裝備武器:" << item[0] << endl;
    cout << "裝備防具:" << item[1] << endl;
    cout << "---------------------------------------------" << endl;
    return 0;
}
//魔力
int Mana(int x)
{
    if (role_type == "戰士")
    {
        M = H / 2;
    }
    else if (role_type == "法師")
    {
        M = H * 2;
    }
    else if (role_type == "射手")
    {
        M = (H * 3) / 2;
    }
    else if (role_type == "牧師")
    {
        M = H * 2;
    }

    return 0;
}
//舊角色
int load_world(int x)
{

    system("cls");
    cout << "請選擇想要使用的角色" << endl;
    ifstream player;
    player.open("player.txt");
    string role;

    int c = 0;
    string trush;
    while (player >> role)
    {
        if (role == acc)
        {
            player >> all_role[c][0] >> all_role[c][1] >> all_able[c][0] >> all_able[c][1] >> all_able[c][2] >> all_able[c][3] >> all_able[c][4] >> all_able[c][5] >> all_able[c][6] >> all_able[c][7];
            for (int i = 0; i < 8; i++)
            {
                player >> arms_bag_count2[c][i];
            }
            for (int i = 0; i < 5; i++)
            {
                player >> armor_bag_count2[c][i];
            }
            for (int i = 0; i < 5; i++)
            {
                player >> food_bag_count2[c][i];
            }
            for (int i = 0; i < 2; i++)
            {
                player >> item_count2[c][i];
            }
            player >> all_able[c][8];
            c = c + 1;
        }
        else
        {
            for (int i = 0; i < 31; i++)
            {
                player >> trush;
            }
        }
    }
    if (c == 0)
    {
        system("cls");
        cout << "此帳戶尚未創建角色" << endl << "請創建一隻新角色" << endl;
        return 1;
    }
    int ans_role;
    for (int i = 0; i < c; i++)
    {
        cout << i + 1 << ".";
        cout << all_role[i][0] << "  " << all_role[i][1] << " " << all_able[i][0] << "等" << endl;
    }
    role_count = c;
    cin >> ans_role;
    ans_role = ans_role - 1;
    name = all_role[ans_role][0]; role_type = all_role[ans_role][1];
    LV = all_able[ans_role][0]; H = all_able[ans_role][1]; A = all_able[ans_role][2];
    B = all_able[ans_role][3]; C = all_able[ans_role][4]; D = all_able[ans_role][5];
    S = all_able[ans_role][6]; money = all_able[ans_role][7]; LV_total = all_able[ans_role][8];
    for (int i = 0; i < 8; i++)
    {
        arms_bag_count[i] = arms_bag_count2[ans_role][i];
    }
    for (int i = 0; i < 5; i++)
    {
        armor_bag_count[i] = armor_bag_count2[ans_role][i];
        food_bag_count[i] = food_bag_count2[ans_role][i];
    }
    for (int i = 0; i < 2; i++)
    {
        item[i] = item_count2[ans_role][i];
    }
    player.close();

    ifstream account_box;
    account_box.open("accountbox.txt");
    string account_name;
    int account_item;
    while (account_box >> account_name)
    {
        if (account_name == acc)
        {
            for (int i = 0; i < 8; i++)
            {
                account_box >> account_item;
                account_arms_bag_count[i] = account_item;
            }
            for (int i = 0; i < 5; i++)
            {
                account_box >> account_item;
                account_armor_bag_count[i] = account_item;
            }
            for (int i = 0; i < 5; i++)
            {
                account_box >> account_item;
                account_food_bag_count[i] = account_item;
            }
            break;
        }
        else
        {
            for (int i = 0; i < 18; i++)
            {
                account_box >> account_item;
            }
        }
    }
    account_box.close();
    return 0;
}
//新角色
int new_world(int x)
{
    ifstream player;
    player.open("player.txt");
    string count_role_run;
    count_role = 0;
    money = 1000;
    LV = 1;
    LV_total = 0;
    while (player >> count_role_run)
    {
        if (count_role_run == acc)
        {
            count_role++;
        }
        for (int i = 0; i < 29; i++)
        {
            player >> count_role_run;
        }
    }
    player.close();
    if (x != 1)
    {
        system("cls");
    }
    if (count_role >= 3)
    {
        system("cls");
        cout << "你創的角色已經達最大數量" << endl << "請改為登入角色" << endl;
        enter_type(0);
        load_world(3);
    }
    else
    {
        cout << "創建角色" << endl;
        cout << "請輸入角色名稱" << endl;
        cin >> name;
        cout << "請選擇職業" << endl;
        string word;
        ifstream fin;
        fin.open("Profession.txt");
        cout << "---------------------------------------------" << endl;
        while (fin >> word)
        {
            cout << word << endl;
        }
        cout << "---------------------------------------------" << endl;
        string choose;
        cin >> choose;
        ifstream role;
        role.open("Role.txt");
        string R;
        int X = 0;
        if (choose == "1")
        {

        }
        else if (choose == "2")
        {
            for (int i = 0; i < 7; i++)
            {
                role >> R;
            }
        }
        else if (choose == "3")
        {
            for (int i = 0; i < 14; i++)
            {
                role >> R;
            }
        }
        else if (choose == "4")
        {
            for (int i = 0; i < 21; i++)
            {
                role >> R;
            }
        }
        else
        {
            cout << "Error_role" << endl;
            X = 1;
        }
        if (X == 0)
        {
            role >> R >> H >> A >> B >> C >> D >> S;
            cout << "職業:" << R << " " << LV << "等" << endl;
            cout << "血量:" << H << endl;
            cout << "物攻:" << A << endl;
            cout << "魔攻:" << B << endl;
            cout << "物防:" << C << endl;
            cout << "魔防:" << D << endl;
            cout << "速度:" << S << endl;
            cout << "現有金錢:" << money << endl;
        }
        role_type = R;
        role.close();
        fin.close();
    }

    return 0;
}
//走路
int walk(int x)
{
rewalk:
    cout << "請問想移動到哪邊去呢" << endl;
    cout << "1.左邊" << endl << "2.右邊" << endl;
    string move; cin >> move;
    if (move == "1")
    {
        if (site - 1 < 0)
        {
            cout << "你沒辦法過去那邊" << endl;
            goto rewalk;
        }
        else
        {
            site--;
        }
    }
    else if (move == "2")
    {
        if (site + 1 > 4)
        {
            cout << "你沒辦法過去那邊" << endl;
            goto rewalk;
        }
        else
        {
            site++;
        }
    }
    else
    {
        cout << "Error_walk_move" << endl;
    }
    return 0;
}
//傳送
int tp(int x)
{
retp:
    cout << "請問想移動到哪邊去呢" << endl;
    cout << "1.王宮" << endl << "2.主城" << endl << "3.森林" << endl << "4.洞窟" << endl << "5.龍窩" << endl;
    int move; cin >> move;
    if (move - 1 == site)
    {
        cout << "你已經在那邊囉，請換個地方逛逛吧" << endl;
        goto retp;
    }
    else
    {
        if (move > 5)
        {
            cout << "跑到邊界外了，請重新傳送" << endl;
            goto retp;
        }
        else
        {
            site = move - 1;
        }
    }
    return 0;
}
//地圖
void map(int x)
{
    string pmap[5] = { "王宮","主城","森林","洞窟","龍窩" };
    cout << "世界地圖:" << endl;
    cout << "王宮----主城----森林----洞窟----龍窩" << endl;
    cout << endl;
    cout << "目前位置:" << pmap[site] << endl;
    cout << "你想怎麼移動呢" << endl;
    cout << "1.走路" << endl;
    cout << "2.傳送" << endl;
    string move;
    cin >> move;
    if (move == "1")
    {
        walk(0);
        cout << "到達" << pmap[site] << endl;
    }
    else if (move == "2")
    {
        tp(0);
        cout << "到達" << pmap[site] << endl;
    }
    else
    {
        cout << "Error_map_move" << endl;
    }
    ifstream map;
    string AA;
    map.open("map.txt");
    for (int i = 0; i < site; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map >> AA;
        }
    }
    for (int j = 0; j < 4; j++)
    {
        map >> AA;
        cout << AA;
    }

    map.close();
}
//開始畫面
int start(string x)
{
    int new_in = 0, old_in = 0;

    do
    {
        if (x == "1")
        {
            system("cls");
            cout << "新遊戲開始" << endl;
            new_world(0);
        }
        else if (x == "2")
        {
            system("cls");
            cout << "請選取你想要讀取的紀錄" << endl;
            load_world(old_in);
        }
        else if (x == "3")
        {
            cout << "感謝您的遊玩" << endl;
        }
        else
        {
            x = "0";
        }
    } while (x == "0");
    return 0;
}
//創建新帳戶
string new_account(int x)
{
    system("cls");
re_account:
    cout << "請輸入你你想創造的帳號密碼" << endl;
    ofstream fout;
    ifstream fin;
    string ac, pw;
    cin >> ac >> pw;
    fout.open("account.txt", fout.app);
    fin.open("account.txt");
    string pac, ppw;
    while (fin >> pac >> ppw)
    {
        if (pac == ac)
        {
            string check;
            cout << "此帳戶已經存在，請更改帳戶名稱或是直接登入" << endl;
            cout << "1.更改帳戶名稱" << endl << "2.直接帳號登入" << endl;
            cin >> check;
            if (check == "1")
            {
                goto re_account;
                break;
            }
            else if (check == "2")
            {
                return "2";
                break;
            }
            else
            {
                cout << "Error_new_account" << endl;
            }
        }
        else
        {
            continue;
        }
    }
    acc = ac;
    fout << acc << endl << pw << endl;
    system("cls");
    cout << acc << "您好" << endl;
    fin.close();
    fout.close();
    ofstream account_box;
    account_box.open("accountbox.txt", account_box.app);
    account_box << acc << endl;
    for (int i = 0; i < 8; i++)
    {
        account_box << "0 ";
    }
    account_box << endl;
    for (int i = 0; i < 5; i++)
    {
        account_box << "0 ";
    }
    account_box << endl;
    for (int i = 0; i < 5; i++)
    {
        account_box << "0 ";
    }
    account_box << endl;
    account_box.close();
    return ac;
}
//直接登入
string last_account(int x)
{
    int in_count = 0;
re_ans:
    cout << "請輸入你的帳號密碼" << endl;
    string ac, pw;
    cin >> ac >> pw;
    ifstream fin;
    fin.open("account.txt");
    string pac, ppw;
    fin >> pac >> ppw;
    int check = 0;
    do
    {
        if (pw == "11111111111")
        {
        re_pass:
            cout << "\n請重新輸入密碼" << endl;
            cin >> pw;
        }

        if (ac == pac && pw == ppw)
        {
            system("cls");
            cout << ac << "歡迎回來" << endl;
            acc = ac;
            return ac;
            break;
        }
        else if (ac == pac && pw != ppw)
        {
            if (in_count <= 1)
            {
                cout << "\n密碼輸入錯誤，請重新輸入" << endl;
                in_count++;
                goto re_pass;
            }
            else
            {
            re_forgot:
                cout << "密碼輸入錯誤" << endl << "1.重新輸入" << endl << "2.忘記密碼" << endl;
                string ans;
                cin >> ans;
                acc = ac;
                if (ans == "1")
                {
                    last_account(0);
                }
                else if (ans == "2")
                {
                    return "3";
                }
                else
                {
                    goto re_forgot;
                }
            }

            check = 0;
            break;
        }
        else
        {
            check = 1;
            continue;
        }
    } while (fin >> pac >> ppw);
    if (check == 1)
    {
        system("cls");
        string check;
        cout << "查無此帳號" << "需要創造新帳號嗎？" << endl;
        cout << "1.創新帳號" << endl << "2.重新輸入帳號密碼" << endl;
        cin >> check;

        if (check == "1")
        {
            acc = new_account(0);
            system("cls");
            cout << acc << "您好" << endl;
        }
        else if (check == "2")
        {
            goto re_ans;
        }
        else
        {
            cout << "Error_account_check" << endl;
            return "";
        }
    }

    fin.close();
    acc = ac;
    return ac;
}
//忘記密碼
int find_account(string x)
{
    cout << "請輸入你想要換的密碼" << endl;
    string re_pw;
    cin >> re_pw;
    ifstream account;
    ofstream account2;
    account.open("account.txt");
    account2.open("account2.txt");
    string ac;
    while (account >> ac)
    {
        if (ac != x)
        {
            account2 << ac << endl;
            account >> ac;
            account2 << ac << endl;
        }
        else
        {
            account >> ac;
        }
    }
    account2 << x << endl << re_pw << endl;
    cout << "\n你已經把密碼換成了\t" << re_pw << endl;


    account.close();
    account2.close();
    remove("account.txt");
    rename("account2.txt", "account.txt");
    return 0;
}
//藥水商店
int food_shoping(int x)
{
re_food_shop:
    ifstream food_shop;
    food_shop.open("food.txt");
    string food_name[10], food_role[10];
    int food_value[10], food_money[10];
    int c = 0;
    string ans;
    while (food_shop >> food_name[c])
    {
        food_shop >> food_value[c] >> food_money[c] >> food_role[c];
        cout << c + 1 << ".";
        if (food_role[c] == "h")
        {
            cout << food_name[c] << endl << food_value[c] << "回血量" << endl << food_money[c] << "元" << endl;
        }
        else if (food_role[c] == "a")
        {
            cout << food_name[c] << endl << food_value[c] << "物攻" << endl << food_money[c] << "元" << endl;
        }
        else if (food_role[c] == "b")
        {
            cout << food_name[c] << endl << food_value[c] << "魔攻" << endl << food_money[c] << "元" << endl;
        }
        else if (food_role[c] == "c")
        {
            cout << food_name[c] << endl << food_value[c] << "物防" << endl << food_money[c] << "元" << endl;
        }
        c++;
    }
    cout << c + 1 << ".離開商店" << endl;
    cout << "現在金額:" << money << endl;
    cout << "請輸入想購買的藥水" << endl;
    int choose; cin >> choose;
    if (c + 1 == choose)
    {
        goto leave_food_shop;
    }
    if (money >= food_money[choose - 1])
    {
        food_bag_count[choose - 1]++;
        money -= food_money[choose - 1];
        cout << endl << "以購買" << food_name[choose - 1] << endl << endl;
    }
    else
    {
        cout << "不好意思，你的錢沒有帶夠唷" << endl;
    }
    cout << "請問你要繼續購買嗎" << endl;
    cout << "1.繼續待在藥水商店" << endl << "2.更換商店" << endl << "3.離開" << endl;
    cin >> ans;
    if (ans == "1")
    {
        goto re_food_shop;
    }
    else if (ans == "2")
    {
        return 1;
    }
    else if (ans == "3")
    {
    leave_food_shop:
        cout << "謝謝光臨武器商店" << endl;
    }
    else
    {
        cout << "Error_food_shoping" << endl;
    }
    food_shop.close();
    return 0;
}
//裝備商店
int armor_shoping(int x)
{
re_armor_shop:
    ifstream armor_shop;
    armor_shop.open("armor.txt");
    string armor_name[10];
    int armor_value[10], armor_money[10] = { 0 };
    int c = 0;
    string ans;
    while (armor_shop >> armor_name[c])
    {
        armor_shop >> armor_value[c] >> armor_money[c];
        cout << c + 1 << ".";
        cout << armor_name[c] << endl << armor_value[c] << "血量" << endl << armor_money[c] << "元" << endl;
        c++;
    }
    cout << c + 1 << ".離開商店" << endl;
    cout << "現在金額:" << money << endl;
    cout << "請輸入想購買的武器" << endl;
    int choose; cin >> choose;
    if (c + 1 == choose)
    {
        goto leave_armor_shop;
    }
    if (money >= armor_money[choose - 1])
    {
        armor_bag_count[choose - 1]++;
        money -= armor_money[choose - 1];
        cout << endl << "以購買" << armor_name[choose - 1] << endl << endl;
    }
    else
    {
        cout << "不好意思，你的錢沒有帶夠唷" << endl;
    }
    cout << "請問你要繼續購買嗎" << endl;
    cout << "1.繼續待在裝甲商店" << endl << "2.更換商店" << endl << "3.離開" << endl;
    cin >> ans;
    if (ans == "1")
    {
        goto re_armor_shop;
    }
    else if (ans == "2")
    {
        return 1;
    }
    else if (ans == "3")
    {
    leave_armor_shop:
        cout << "謝謝光臨武器商店" << endl;
    }
    else
    {
        cout << "Error_armor_shoping" << endl;
    }
    armor_shop.close();
    return 0;
}
//武器商店
int arms_shoping(int x)
{
re_arms_shop:
    ifstream arms_shop;
    arms_shop.open("arms.txt");
    string arms_name[10], arms_role[10];
    int arms_value[10], arms_money[10];
    int c = 0;
    string ans;
    while (arms_shop >> arms_name[c])
    {
        arms_shop >> arms_value[c] >> arms_money[c] >> arms_role[c];
        cout << c + 1 << ".";
        if (arms_role[c] == "戰士")
        {
            cout << arms_name[c] << endl << arms_value[c] << "物攻" << endl << arms_money[c] << "元" << endl;
        }
        else if (arms_role[c] == "法師")
        {
            cout << arms_name[c] << endl << arms_value[c] << "魔攻" << endl << arms_money[c] << "元" << endl;
        }
        else if (arms_role[c] == "射手")
        {
            cout << arms_name[c] << endl << arms_value[c] << "物攻" << endl << arms_money[c] << "元" << endl;
        }
        else if (arms_role[c] == "牧師")
        {
            cout << arms_name[c] << endl << arms_value[c] << "魔攻" << endl << arms_money[c] << "元" << endl;
        }
        c++;
    }
    cout << c + 1 << ".離開商店" << endl;
    cout << "現在金額:" << money << endl;
    cout << "請輸入想購買的武器" << endl;
    int choose; cin >> choose;
    if (c + 1 == choose)
    {
        goto leave_arms_shop;
    }
    if (money >= arms_money[choose - 1])
    {
        arms_bag_count[choose - 1]++;
        money -= arms_money[choose - 1];
        cout << endl << "以購買" << arms_name[choose - 1] << endl << endl;
    }
    else
    {
        cout << "不好意思，你的錢沒有帶夠唷" << endl;
    }
    cout << "請問你要繼續購買嗎" << endl;
    cout << "1.繼續待在武器商店" << endl << "2.更換商店" << endl << "3.離開" << endl;
    cin >> ans;
    if (ans == "1")
    {
        goto re_arms_shop;
    }
    else if (ans == "2")
    {
        return 1;
    }
    else if (ans == "3")
    {
    leave_arms_shop:
        cout << "謝謝光臨武器商店" << endl;
    }
    else
    {
        cout << "Error_arms_shoping" << endl;
    }
    arms_shop.close();
    return 0;
}
//商店
int shop(int x)
{
re_shop:
    cout << endl;
    if (site > 1)
    {
        cout << "你必須回到主城內才能夠進入商店\n" << endl;
        return 0;
    }
    cout << "歡迎來到商店,請問你想要買些什麼呢" << endl;
    cout << "1.武器" << endl;
    cout << "2.防具" << endl;
    cout << "3.藥水" << endl;
    cout << "4.離開商店" << endl;
    string ans; cin >> ans;
    if (ans == "1")
    {
        int change_shop;
        change_shop = arms_shoping(0);
        if (change_shop)
        {
            goto re_shop;
        }
    }
    else if (ans == "2")
    {
        int change_shop;
        change_shop = armor_shoping(0);
        if (change_shop)
        {
            goto re_shop;
        }
    }
    else if (ans == "3")
    {
        int change_shop;
        change_shop = food_shoping(0);
        if (change_shop)
        {
            goto re_shop;
        }
    }
    else
    {
        cout << "輸入錯誤，請重新輸入" << endl;
        goto re_shop;
    }
    return 0;
}
//怪物
int monster(int x)
{
    unsigned seed;
    seed = (unsigned)time(NULL);
    ofstream monster;
    monster.open("monster.txt");
    int monster_role, moster_LV;
    if (site == 0 || site == 1)
    {
        cout << "\n身處在安全地帶，沒有任何野怪" << endl;
    }
    else if (site == 2)
    {
        cout << "現在位置為[ 森林 ]" << endl;
        for (int i = 0; i < 5; i++)
        {
            monster_role = rand() % 4;
            moster_LV = (rand() % 5) * LV + 1;
            monster << i + 1 << " " << monster_name[monster_role] << " " << moster_LV << endl;
            monster_value[i][0] = moster_LV * 10; monster_value[i][1] = moster_LV * 10; monster_value[i][2] = moster_LV * 10;
            monster_value[i][3] = moster_LV * 10; monster_value[i][4] = moster_LV * 10; monster_value[i][5] = moster_LV * 10;
            monster_value[i][6] = moster_LV;
            battle_name[i] = monster_name[monster_role];
        }
    }
    else if (site == 3)
    {
        cout << "現在位置為[ 洞窟 ]" << endl;
        for (int i = 0; i < 3; i++)
        {
            monster_role = rand() % 2 + 4;
            moster_LV = (rand() % 7) * LV + 10;
            monster << i + 1 << " " << monster_name[monster_role] << " " << moster_LV << endl;
            monster_value[i][0] = moster_LV * 30; monster_value[i][1] = moster_LV * 30; monster_value[i][2] = moster_LV * 30;
            monster_value[i][3] = moster_LV * 30; monster_value[i][4] = moster_LV * 30; monster_value[i][5] = moster_LV * 30;
            monster_value[i][6] = moster_LV;
            battle_name[i] = monster_name[monster_role];
        }
    }
    else if (site == 4)
    {
        cout << "現在位置為[ 龍窩 ]" << endl;
        for (int i = 0; i < 1; i++)
        {
            monster_role = rand() % 2 + 6;
            moster_LV = (rand() % 10) * LV + 20;
            monster << i + 1 << " " << monster_name[monster_role] << " " << moster_LV << endl;
            monster_value[i][0] = moster_LV * 50; monster_value[i][1] = moster_LV * 50; monster_value[i][2] = moster_LV * 50;
            monster_value[i][3] = moster_LV * 50; monster_value[i][4] = moster_LV * 50; monster_value[i][5] = moster_LV * 50;
            monster_value[i][6] = moster_LV;
            battle_name[i] = monster_name[monster_role];
        }
    }
    monster.close();
    return 0;
}
//使用技能
int skill_use(int x)
{
    unsigned seed;
    seed = (unsigned)time(NULL);
    string skill_name, damage, effect;
    if (LV / 5 == 0)
    {
        cout << "你目前還沒學會任何的技能" << endl;
    }
    if (role_type == "戰士")
    {
    re_choose_skill:
        ifstream warrior;
        warrior.open("warrior.txt");
        for (int i = 0; i < LV / 5; i++)
        {
            warrior >> skill_name >> damage >> effect;
            cout << i + 1 << "." << skill_name << " 所需MP:" << damage << endl;
        }
        cout << (LV / 5) + 1 << "." << "取消" << endl;
        int choose; cin >> choose;
        if (choose == (LV / 5) + 1)
        {
            return 1;
        }
        else
        {
            Sleep(500); cout << ".\n";
            Sleep(500); cout << "..\n";
            Sleep(500); cout << "...\n";
            if (choose == 1)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    warrior.close();
                    goto re_choose_skill;
                }
                if ((A + fake_A + 100) * 2 - monster_value[x - 1][3] >= 0)
                {
                    cout << "你使用了技能[ 重擊 ]對 " << battle_name[x - 1] << " 造成了 " << (A + fake_A + 100) * 2 - monster_value[x - 1][3] << "點傷害" << endl;
                    monster_Hp_now -= (A + fake_A + 100) * 2 - monster_value[x - 1][3];
                }
                else
                {
                    cout << "你使用了技能[ 重擊 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害" << endl;
                }
                M_now -= 100;
            }
            else if (choose == 2)
            {
                if (M_now <= 200)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    warrior.close();
                    goto re_choose_skill;
                }
                if ((A + fake_A + 200) - monster_value[x - 1][3] >= 0)
                {
                    cout << "你使用了技能[ 迴旋砍 ]對 " << battle_name[x - 1] << " 造成了 " << (A + fake_A + 200) - monster_value[x - 1][3] << "點傷害2次" << endl;
                    monster_Hp_now -= (A + fake_A + 200) - monster_value[x - 1][3];
                    monster_Hp_now -= (A + fake_A + 200) - monster_value[x - 1][3];
                }
                else
                {
                    cout << "你使用了技能[ 迴旋砍 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害2次" << endl;
                }
                M_now -= 200;
            }
            else if (choose == 3)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    warrior.close();
                    goto re_choose_skill;
                }
                fake_C = C;
                cout << "你使用了技能[ 格擋 ]，你的防禦力變成了原本的2倍了" << endl;
                M_now -= 100;
            }
            else if (choose == 4)
            {
                H_now = H_now / 2;
                fake_A = A * 2;
                cout << "你使用了技能[ 血怒 ]，你的生命值剩下一半，但是你的攻擊力提升成了三倍" << endl;
            }

        }
        warrior.close();
    }
    else if (role_type == "法師")
    {
    re_choose_mage:
        ifstream mage;
        mage.open("mage.txt");
        for (int i = 0; i < LV / 5; i++)
        {
            mage >> skill_name >> damage >> effect;
            cout << i + 1 << "." << skill_name << " 所需MP:" << damage << endl;
        }
        cout << (LV / 5) + 1 << "." << "取消" << endl;
        int choose; cin >> choose;
        if (choose == (LV / 5) + 1)
        {
            return 1;
        }
        else
        {
            Sleep(500); cout << ".\n";
            Sleep(500); cout << "..\n";
            Sleep(500); cout << "...\n";
            if (choose == 1)
            {

                if (M_now <= 50)
                {
                    cout << "目前MP不夠，使用這招需要50MP，請重新選擇" << endl;
                    mage.close();
                    goto re_choose_mage;
                }
                M_now -= 50;
                int r; r = rand() % 10;
                if (r >= 5)
                {
                    if ((B + fake_B + 50) - monster_value[x - 1][3] >= 0)
                    {
                        cout << "你使用了技能[ 火球 ]對 " << battle_name[x - 1] << " 造成了 " << (B + fake_B + 50) - monster_value[x - 1][3] << "點傷害並且成功灼傷了對手" << endl;
                        monster_Hp_now -= (B + fake_B + 50) - monster_value[x - 1][3];
                    }
                    else
                    {
                        cout << "你使用了技能[ 火球 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害並且成功灼傷了對手" << endl;
                    }
                    return 21;
                }
                else
                {
                    if ((B + fake_B + 50) - monster_value[x - 1][3] >= 0)
                    {
                        cout << "你使用了技能[ 火球 ]對 " << battle_name[x - 1] << " 造成了 " << (B + fake_B + 50) - monster_value[x - 1][3] << "點傷害" << endl;
                        monster_Hp_now -= (B + fake_B + 50) - monster_value[x - 1][3];
                    }
                    else
                    {
                        cout << "你使用了技能[ 火球 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害" << endl;
                    }
                }

            }
            else if (choose == 2)
            {
                if (M_now <= 50)
                {
                    cout << "目前MP不夠，使用這招需要50MP，請重新選擇" << endl;
                    mage.close();
                    goto re_choose_mage;
                }
                M_now -= 50;
                int r; r = rand() % 10;
                if (r >= 5)
                {
                    if ((B + fake_B + 50) - monster_value[x - 1][3] >= 0)
                    {
                        cout << "你使用了技能[ 冰雹 ]對 " << battle_name[x - 1] << " 造成了 " << (B + fake_B + 50) - monster_value[x - 1][3] << "點傷害並且成功凍傷了對手" << endl;
                        monster_Hp_now -= (B + fake_B + 50) - monster_value[x - 1][3];
                    }
                    else
                    {
                        cout << "你使用了技能[ 冰雹 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害並且成功凍傷了對手" << endl;
                    }
                    return 22;
                }
                else
                {
                    if ((B + fake_B + 50) - monster_value[x - 1][3] >= 0)
                    {
                        cout << "你使用了技能[ 冰雹 ]對 " << battle_name[x - 1] << " 造成了 " << (B + fake_B + 50) - monster_value[x - 1][3] << "點傷害" << endl;
                        monster_Hp_now -= (B + fake_B + 50) - monster_value[x - 1][3];
                    }
                    else
                    {
                        cout << "你使用了技能[ 冰雹 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害" << endl;
                    }
                }
            }
            else if (choose == 3)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    mage.close();
                    goto re_choose_mage;
                }
                M_now -= 100;
                fake_B = B;
                cout << "你使用了技能[ 冥想 ]，你的魔攻變成了原本的2倍了" << endl;
            }
            else if (choose == 4)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    mage.close();
                    goto re_choose_mage;
                }
                M_now -= 100;
                cout << "你使用了技能[ 魔法屏障 ]，下次對手攻擊將不會命中你" << endl;
                return 24;
            }
        }
        mage.close();
    }
    else if (role_type == "射手")
    {
    re_shooter:
        ifstream shooter;
        shooter.open("shooter.txt");
        for (int i = 0; i < LV / 5; i++)
        {
            shooter >> skill_name >> damage >> effect;
            cout << i + 1 << "." << skill_name << " 所需MP:" << damage << endl;
        }
        cout << (LV / 5) + 1 << "." << "取消" << endl;
        int choose; cin >> choose;
        if (choose == (LV / 5) + 1)
        {
            return 1;
        }
        else
        {
            Sleep(500); cout << ".\n";
            Sleep(500); cout << "..\n";
            Sleep(500); cout << "...\n";
            if (choose == 1)
            {
                if (M_now <= 50)
                {
                    cout << "目前MP不夠，使用這招需要50MP，請重新選擇" << endl;
                    shooter.close();
                    goto re_shooter;
                }
                M_now -= 50;
                if ((A + fake_A + 50) >= 0)
                {
                    cout << "你使用了技能[ 穿甲箭 ]對 " << battle_name[x - 1] << " 造成了 " << (A + fake_A + 50) << "點傷害" << endl;
                    monster_Hp_now -= (A + fake_A + 50);
                }
            }
            else if (choose == 2)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    shooter.close();
                    goto re_shooter;
                }
                M_now -= 100;
                if ((A + fake_A + 100) - monster_value[x - 1][3] >= 0)
                {
                    cout << "你使用了技能[ 暴風箭 ]對 " << battle_name[x - 1] << " 造成了 " << (A + fake_A + 100) - monster_value[x - 1][3] << "點傷害3次" << endl;
                    monster_Hp_now -= (A + fake_A + 100) - monster_value[x - 1][3];
                    monster_Hp_now -= (A + fake_A + 100) - monster_value[x - 1][3];
                    monster_Hp_now -= (A + fake_A + 100) - monster_value[x - 1][3];
                }
                else
                {
                    cout << "你使用了技能[ 暴風箭 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害3次" << endl;
                }
            }
            else if (choose == 3)
            {
                if (M_now <= 200)
                {
                    cout << "目前MP不夠，使用這招需要200MP，請重新選擇" << endl;
                    shooter.close();
                    goto re_shooter;
                }
                M_now -= 200;
                fake_A = A;
                cout << "你使用了技能[ 蓄力 ]，接下來的每一發箭矢都會爆擊" << endl;
            }
            else if (choose == 4)
            {
                if (M_now <= 200)
                {
                    cout << "目前MP不夠，使用這招需要200MP，請重新選擇" << endl;
                    shooter.close();
                    goto re_shooter;
                }
                M_now -= 200;
                fake_S = S;
                cout << "你使用了技能[ 凌波微步 ]，你的速度變成了兩倍" << endl;
            }
        }
        shooter.close();
    }
    else if (role_type == "牧師")
    {
    re_priest:
        ifstream priest;
        priest.open("priest.txt");
        for (int i = 0; i < LV / 5; i++)
        {
            priest >> skill_name >> damage >> effect;
            cout << i + 1 << "." << skill_name << " 所需MP:" << damage << endl;
        }
        cout << (LV / 5) + 1 << "." << "取消" << endl;
        int choose; cin >> choose;
        if (choose == (LV / 5) + 1)
        {
            return 1;
        }
        else
        {
            Sleep(500); cout << ".\n";
            Sleep(500); cout << "..\n";
            Sleep(500); cout << "...\n";
            if (choose == 1)
            {
                if (M_now <= 50)
                {
                    cout << "目前MP不夠，使用這招需要50MP，請重新選擇" << endl;
                    priest.close();
                    goto re_priest;
                }
                M_now -= 50;
                if (B + fake_B + H_now <= H)
                {
                    cout << "你使用了技能[ 聖光術 ]幫自己回了 " << B + fake_B + H_now << "點生命" << endl;
                }
                else
                {
                    cout << "你使用了技能[ 聖光術 ]幫自己回到滿血了" << endl;
                }
            }
            else if (choose == 2)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    priest.close();
                    goto re_priest;
                }
                M_now -= 100;
                if ((B + fake_B + 100) - monster_value[x - 1][3] >= 0)
                {
                    cout << "你使用了技能[ 暗影術 ]對 " << battle_name[x - 1] << " 造成了 " << (B + fake_B + 100) - monster_value[x - 1][3] << "點傷害" << endl;
                    monster_Hp_now -= (B + fake_B + 100) - monster_value[x - 1][4];
                }
                else
                {
                    cout << "你使用了技能[ 暗影術 ]對 " << battle_name[x - 1] << " 造成了 " << 0 << "點傷害" << endl;
                }
            }
            else if (choose == 3)
            {
                if (M_now <= 100)
                {
                    cout << "目前MP不夠，使用這招需要100MP，請重新選擇" << endl;
                    priest.close();
                    goto re_priest;
                }
                M_now -= 100;
                fake_B = B;
                cout << "你使用了技能[ 靈氣領域 ]，你的魔攻變成了原本的2倍了" << endl;
            }
            else if (choose == 4)
            {
                if (M_now <= 200)
                {
                    cout << "目前MP不夠，使用這招需要200MP，請重新選擇" << endl;
                    priest.close();
                    goto re_priest;
                }
                M_now -= 200;
                cout << "你使用了技能[ 詛咒 ]，對手在接下來的每個回合都會損失大量的血量，直到死亡" << endl;
                return 44;
            }
        }
        priest.close();
    }
    return 0;
}
//使用藥水
int food_use(int x)
{
    int choose_num = 1;
    int re_ans[5] = { 0 };
    cout << "請選擇你想要使用的藥水" << endl << endl;
    for (int i = 0; i < 5; i++)
    {
        if (food_bag_count[i] > 0)
        {
            cout << choose_num << "." << food_bag[i] << endl;
            re_ans[choose_num - 1] = i;
            choose_num++;
        }
    }
    if (choose_num == 1)
    {
        cout << "\n你目前沒有任何藥水可以使用" << endl;
    }
    cout << choose_num << ".取消" << endl;
    int ans; cin >> ans;
    if (ans == choose_num)
    {
        return 1;
    }
    else
    {
        cout << "你使用了" << food_bag[re_ans[ans - 1]] << endl;
        food_bag_count[re_ans[ans - 1]]--;
        if (re_ans[ans - 1] == 0)
        {
            if (H_now + 50 >= H)
            {
                cout << "你已經回到了滿血" << endl;
            }
            else
            {
                cout << "你的血量已經回到了 " << H_now + 50 << endl;
            }
        }
        else if (re_ans[ans - 1] == 1)
        {
            if (H_now + 100 >= H)
            {
                cout << "你已經回到了滿血" << endl;
            }
            else
            {
                cout << "你的血量已經回到了 " << H_now + 100 << endl;
            }
        }
        else if (re_ans[ans - 1] == 2)
        {
            cout << "你的物防和魔防提升了100點數值" << endl;
            D += 100;
            C += 100;
        }
        else if (re_ans[ans - 1] == 3)
        {
            cout << "你的魔攻提升了100點數值" << endl;
            B += 100;
        }
        else if (re_ans[ans - 1] == 4)
        {
            cout << "你的物攻提升了100點數值" << endl;
            A += 100;
        }
    }

    return 0;
}
//戰鬥畫面
int battle(int x)
{
    int re_skill;
    fake_A = 0; fake_B = 0;
    fake_C = 0; fake_S = 0;
    fire = 0, ice = 0, miss = 0, curse = 0;
    while (monster_Hp_now > 0 && H_now > 0)
    {
    re_battle:
        cout << "---------------------------------------------" << endl;
        cout << "LV:" << monster_value[x - 1][6] << "\t" << battle_name[x - 1] << "\t";
        cout << "HP:" << monster_Hp_now << "/" << monster_value[x - 1][0] << " ";
        cout << "[";

        for (int i = 0; i < monster_Hp_now * 10 / monster_value[x - 1][0]; i++)
        {
            cout << "//";
        }
        for (int i = 0; i < 10 - (monster_Hp_now * 10 / monster_value[x - 1][0]); i++)
        {
            cout << "  ";
        }
        cout << "]" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << endl;
        }
        cout << "LV:" << LV << "\t" << name << "\t";
        cout << "HP:" << H_now << "/" << H << " ";
        cout << "[";
        for (int i = 0; i < H_now * 10 / H; i++)
        {
            cout << "//";
        }
        for (int i = 0; i < 10 - (H_now * 10 / H); i++)
        {
            cout << "  ";
        }
        cout << "]";
        cout << "\tMP:" << M_now << "/" << M << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1.普通攻擊\t" << "2.技能" << endl << "3.使用道具\t" << "4.逃走" << endl;
        string choose; cin >> choose;
        if (S + fake_S > monster_value[x - 1][5])
        {
        first_atk:
            if (choose == "1")
            {
                Sleep(500); cout << ".\n";
                Sleep(500); cout << "..\n";
                Sleep(500); cout << "...\n";
                if (A + fake_A - monster_value[x - 1][3] >= 0)
                {

                    monster_Hp_now -= A - monster_value[x - 1][3];
                    cout << "你對" << battle_name[x - 1] << "造成了" << A + fake_A - monster_value[x - 1][3] << "點傷害" << endl;
                }
                else
                {
                    cout << "你沒有傷到怪物任何一滴血" << endl;
                }
            }
            else if (choose == "2")
            {
                re_skill = skill_use(x);
                if (re_skill == 1)
                {
                    goto re_battle;
                }
                else if (re_skill == 21)
                {
                    fire = 1;
                }
                else if (re_skill == 22)
                {
                    ice = 1;
                }
                else if (re_skill == 24)
                {
                    miss = 1;
                }
                else if (re_skill == 44)
                {
                    curse = 1;
                }
            }
            else if (choose == "3")
            {
                food_use(0);
                goto re_battle;
            }
            else if (choose == "4")
            {
                unsigned seed;
                seed = (unsigned)time(NULL);
                int run = rand() % 10;
                Sleep(500); cout << ".\n";
                Sleep(500); cout << "..\n";
                Sleep(500); cout << "...\n";
                if (run >= 5)
                {
                    cout << "\n恭喜你成功逃走\n";
                    return 0;
                }
                else
                {
                    cout << "\n逃脫失敗\n";
                }
            }

            if (monster_Hp_now > 0)
            {
                int ice_rand = rand() % 10;
                if (ice == 1 && ice_rand >= 5)
                {
                    cout << "對手被凍結了，無法出招" << endl;
                }
                else
                {
                    if (ice_rand < 2)
                    {
                        cout << "對手的結凍狀態消除了" << endl;
                        ice = 0;
                    }
                    if (miss == 1)
                    {
                        cout << "你的魔法屏障幫你把這次攻擊擋了下來" << endl;
                        miss = 0;
                    }
                    else if (monster_value[x - 1][1] - C - fake_C >= 0)
                    {
                        H_now -= monster_value[x - 1][1] - C;
                        cout << "\n" << battle_name[x - 1] << "對你進行攻擊，造成了" << monster_value[x - 1][1] - C - fake_C << "點的傷害" << endl;
                    }
                    else
                    {
                        cout << "\n" << battle_name[x - 1] << "對你進行攻擊，造成了" << 0 << "點的傷害" << endl;
                    }
                }

            }
            else
            {
                LV_total += monster_value[x - 1][6] + 20;
                money += monster_value[x - 1][6] + 20;
                cout << "\n恭喜你打贏了LV:" << monster_value[x - 1][6] << "的" << battle_name[x - 1] << endl;
                cout << "你獲得了" << monster_value[x - 1][6] + 20 << "的經驗值" << endl;
                cout << "你獲得了" << monster_value[x - 1][6] + 20 << "money" << endl;
                return 0;
            }
            if (H_now <= 0)
            {
                cout << "你被擊敗了" << endl;
                cout << "你失去了" << LV << "經驗值" << endl;
                LV_total -= LV;
                H_now = H;
                site = 1;
                return 0;
            }
        }
        else if (S + fake_S < monster_value[x - 1][5])
        {
        last_atk:
            if (choose == "3")
            {
                food_use(0);
                goto re_battle;
            }
            else if (choose == "4")
            {
                unsigned seed;
                seed = (unsigned)time(NULL);
                int run = rand() % 10;
                Sleep(500); cout << ".\n";
                Sleep(500); cout << "..\n";
                Sleep(500); cout << "...\n";
                if (run >= 5)
                {
                    cout << "\n恭喜你成功逃走\n";
                    return 0;
                }
                else
                {
                    cout << "\n逃脫失敗\n";
                }
            }
            if (monster_Hp_now > 0)
            {
                int ice_rand = rand() % 10;
                if (ice == 1 && ice_rand >= 5)
                {
                    cout << "對手被凍結了，無法出招" << endl;
                }
                else
                {
                    if (ice_rand < 2)
                    {
                        cout << "對手的結凍狀態消除了" << endl;
                        ice = 0;
                    }
                    if (miss == 1)
                    {
                        cout << "你的魔法屏障幫你把這次攻擊擋了下來" << endl;
                        miss = 0;
                    }
                    else if (monster_value[x - 1][1] - C - fake_C >= 0)
                    {
                        H_now -= monster_value[x - 1][1] - C;
                        cout << "\n" << battle_name[x - 1] << "對你進行攻擊，造成了" << monster_value[x - 1][1] - C - fake_C << "點的傷害" << endl;
                    }
                    else
                    {
                        cout << "\n" << battle_name[x - 1] << "對你進行攻擊，造成了" << 0 << "點的傷害" << endl;
                    }
                }

            }

            if (H_now <= 0)
            {
                cout << "你被擊敗了" << endl;
                cout << "你失去了" << LV << "經驗值" << endl;
                LV_total -= LV;
                H_now = H;
                site = 1;
                return 0;
            }
            if (choose == "1")
            {
                Sleep(500); cout << ".\n";
                Sleep(500); cout << "..\n";
                Sleep(500); cout << "...\n";
                if (A + fake_A - monster_value[x - 1][3] > 0)
                {
                    monster_Hp_now -= A - monster_value[x - 1][3];
                    cout << "你對" << battle_name[x - 1] << "造成了" << A + fake_A - monster_value[x - 1][3] << "點傷害" << endl;
                }
                else
                {
                    cout << "你沒有傷害到怪物任何一滴血" << endl;
                }
            }
            else if (choose == "2")
            {
                re_skill = skill_use(x);
                if (re_skill == 1)
                {
                    goto re_battle;
                }
                else if (re_skill == 21)
                {
                    fire = 1;
                }
                else if (re_skill == 22)
                {
                    ice = 1;
                }
                else if (re_skill == 24)
                {
                    miss = 1;
                }
                else if (re_skill == 44)
                {
                    curse = 1;
                }
            }
            if (monster_Hp_now <= 0)
            {
                LV_total += monster_value[x - 1][6] + 20;
                money += monster_value[x - 1][6] + 20;
                cout << "\n恭喜你打贏了LV:" << monster_value[x - 1][6] << "的" << battle_name[x - 1] << endl;
                cout << "你獲得了" << monster_value[x - 1][6] + 20 << "的經驗值" << endl;
                cout << "你獲得了" << monster_value[x - 1][6] + 20 << "money" << endl;
                return 0;
            }
        }
        else if (S + fake_S == monster_value[x - 1][5])
        {
            int rand_num = rand() % 10;
            if (rand_num >= 5)
            {
                goto first_atk;
            }
            else
            {
                goto last_atk;
            }
        }
        if (fire == 1)
        {
            cout << "你的對手受到了燃燒傷害，一共吃了" << monster_Hp_now / 5 << "滴傷害" << endl;
            monster_Hp_now -= monster_Hp_now / 5;
        }
        if (curse == 1)
        {
            cout << "你的對手受到了詛咒的傷害，一共損失了" << monster_Hp_now / 4 << "的血量" << endl;
            monster_Hp_now -= monster_Hp_now / 4;
        }

    }

    return 0;
}
//技能
int skill(int x)
{
    ifstream warrior;
    ifstream mage;
    ifstream shooter;
    ifstream priest;
    warrior.open("warrior.txt");
    mage.open("mage.txt");
    shooter.open("shooter.txt");
    priest.open("priest.txt");
    string skill_name, damage, effect;
    if (LV == 5)
    {
        if (role_type == "戰士")
        {
            warrior >> skill_name >> damage >> effect;
        }
        else if (role_type == "法師")
        {
            mage >> skill_name >> damage >> effect;
        }
        else if (role_type == "射手")
        {
            shooter >> skill_name >> damage >> effect;
        }
        else if (role_type == "牧師")
        {
            priest >> skill_name >> damage >> effect;
        }
    }
    else if (LV == 10)
    {
        for (int i = 0; i < 1; i++)
        {
            warrior >> skill_name >> damage >> effect;
            mage >> skill_name >> damage >> effect;
            shooter >> skill_name >> damage >> effect;
            priest >> skill_name >> damage >> effect;
        }
        if (role_type == "戰士")
        {
            warrior >> skill_name >> damage >> effect;
        }
        else if (role_type == "法師")
        {
            mage >> skill_name >> damage >> effect;
        }
        else if (role_type == "射手")
        {
            shooter >> skill_name >> damage >> effect;
        }
        else if (role_type == "牧師")
        {
            priest >> skill_name >> damage >> effect;
        }
    }
    else if (LV == 15)
    {
        for (int i = 0; i < 2; i++)
        {
            warrior >> skill_name >> damage >> effect;
            mage >> skill_name >> damage >> effect;
            shooter >> skill_name >> damage >> effect;
            priest >> skill_name >> damage >> effect;
        }
        if (role_type == "戰士")
        {
            warrior >> skill_name >> damage >> effect;
        }
        else if (role_type == "法師")
        {
            mage >> skill_name >> damage >> effect;
        }
        else if (role_type == "射手")
        {
            shooter >> skill_name >> damage >> effect;
        }
        else if (role_type == "牧師")
        {
            priest >> skill_name >> damage >> effect;
        }
    }
    else if (LV == 20)
    {
        for (int i = 0; i < 3; i++)
        {
            warrior >> skill_name >> damage >> effect;
            mage >> skill_name >> damage >> effect;
            shooter >> skill_name >> damage >> effect;
            priest >> skill_name >> damage >> effect;
        }
        if (role_type == "戰士")
        {
            warrior >> skill_name >> damage >> effect;
        }
        else if (role_type == "法師")
        {
            mage >> skill_name >> damage >> effect;
        }
        else if (role_type == "射手")
        {
            shooter >> skill_name >> damage >> effect;
        }
        else if (role_type == "牧師")
        {
            priest >> skill_name >> damage >> effect;
        }
    }
    if (LV % 5 == 0)
    {
        cout << "你學會了" << skill_name << endl;
        cout << "所需MP:" << damage << endl;
        cout << "效果:" << effect << endl;
    }
    warrior.close();
    mage.close();
    shooter.close();
    priest.close();
    return 0;
}
//等級上升
int LV_UP(int x)
{
    for (int i = LV; i < 20; i++)
    {
        if (LV_total >= LV_need[i])
        {
            LV = i + 1;
            if (role_type == "戰士")
            {
                H += 200; A += 50; B += 0; C += 100; D += 100; S += 25; money += 1000;
            }
            else if (role_type == "法師")
            {
                H += 100; A += 0; B += 200; C += 25; D += 50; S += 50; money += 1000;
            }
            else if (role_type == "射手")
            {
                H += 100; A += 200; B += 0; C += 50; D += 25; S += 100; money += 1000;
            }
            else if (role_type == "牧師")
            {
                H += 200; A += 0; B += 100; C += 50; D += 50; S += 50; money += 1000;
            }
            cout << "恭喜你升級到了" << LV << "等" << endl;
            H_now = H;
            Mana(0);
            M_now = M;
            skill(0);
        }
    }
    return 0;
}
//戰鬥
int fighting(int x)
{
    monster(0);
    if (site > 1)
    {
        cout << "請選擇要挑戰的怪物\n" << endl;
        ifstream monster_choose;
        monster_choose.open("monster.txt");
        string monster_Information;
        while (monster_choose >> monster_Information)
        {
            cout << monster_Information << ".";
            monster_choose >> monster_Information;
            cout << monster_Information << "\tLV:";
            monster_choose >> monster_Information;
            cout << monster_Information << endl;
        }
        monster_choose.close();
        int choose; cin >> choose;
        monster_Hp_now = monster_value[choose - 1][0];
        cout << "\n你選擇了" << monster_value[choose - 1][6] << "等的" << battle_name[choose - 1] << "進行挑戰" << endl << endl;
        battle(choose);
        LV_UP(0);
    }
    return 0;
}
//個人to帳號倉庫
int P2A(int x)
{
    cout << endl << "\t請問想要將哪一類的物品移動到帳號倉庫" << endl;
    cout << "1.武器" << endl << "2.裝備" << endl << "3.藥水" << endl << "4.回到倉庫" << endl;
    string ans; cin >> ans;

    if (ans == "1")
    {
    re_choose_arms:
        cout << endl << "\t請選擇下列物品放入帳號倉庫" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i + 1 << "." << arms_bag[i] << "\t現在身上有:" << arms_bag_count[i] << "把" << endl;
        }
        cout << "9." << "直接離開" << endl;
        int item_number;
        cin >> item_number;
        item_number = item_number - 1;
        if (item_number == 8)
        {
            return 0;
        }
        else if (arms_bag_count[item_number] >= 1)
        {
            arms_bag_count[item_number]--;
            account_arms_bag_count[item_number]++;
            cout << "\t已將" << arms_bag[item_number] << "放進帳號倉庫" << endl;
        }
        else
        {
            cout << endl << "你的物品數量不足，請重新選擇" << endl;
            goto re_choose_arms;
        }
    }
    else if (ans == "2")
    {
    re_choose_armor:
        cout << endl << "\t請選擇下列物品放入帳號倉庫" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "." << armor_bag[i] << "\t現在身上有:" << armor_bag_count[i] << "件" << endl;
        }
        cout << "6." << "直接離開" << endl;
        int item_number;
        cin >> item_number;
        item_number = item_number - 1;
        if (item_number == 5)
        {
            return 0;
        }
        else if (armor_bag_count[item_number] >= 1)
        {
            armor_bag_count[item_number]--;
            account_armor_bag_count[item_number]++;
            cout << "\t已將" << armor_bag[item_number] << "放進帳號倉庫" << endl;
        }
        else
        {
            cout << endl << "你的物品數量不足，請重新選擇" << endl;
            goto re_choose_armor;
        }
    }
    else if (ans == "3")
    {
    re_choose_food:
        cout << endl << "\t請選擇下列物品放入帳號倉庫" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "." << food_bag[i] << "\t現在身上有:" << food_bag_count[i] << "瓶" << endl;
        }
        cout << "6." << "直接離開" << endl;
        int item_number;
        cin >> item_number;
        item_number = item_number - 1;
        if (item_number == 5)
        {
            return 0;
        }
        else if (food_bag_count[item_number] >= 1)
        {
            food_bag_count[item_number]--;
            account_food_bag_count[item_number]++;
            cout << "\t已將" << food_bag[item_number] << "放進帳號倉庫" << endl;
        }
        else
        {
            cout << endl << "你的物品數量不足，請重新選擇" << endl;
            goto re_choose_food;
        }
    }

    return 0;
}
//帳號倉庫to個人
int A2P(int x)
{

    cout << endl << "\t請問想要將哪一類的物品移動到帳號倉庫" << endl;
    cout << "1.武器" << endl << "2.裝備" << endl << "3.藥水" << endl << "4.回到倉庫" << endl;
    string ans; cin >> ans;

    if (ans == "1")
    {
    re_account_choose_arms:
        cout << endl << "\t請選擇下列物品放入包包" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i + 1 << "." << arms_bag[i] << "\t現在倉庫有:" << account_arms_bag_count[i] << "把" << endl;
        }
        cout << "9." << "直接離開" << endl;
        int item_number;
        cin >> item_number;
        item_number = item_number - 1;
        if (item_number == 8)
        {
            return 0;
        }
        else if (account_arms_bag_count[item_number] >= 1)
        {
            arms_bag_count[item_number]++;
            account_arms_bag_count[item_number]--;
            cout << "\t已將" << arms_bag[item_number] << "放進包包" << endl;
        }
        else
        {
            cout << endl << "你的倉庫物品數量不足，請重新選擇" << endl;
            goto re_account_choose_arms;
        }
    }
    else if (ans == "2")
    {
    re_account_choose_armor:
        cout << endl << "\t請選擇下列物品放入包包" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "." << armor_bag[i] << "\t現在倉庫有:" << account_armor_bag_count[i] << "件" << endl;
        }
        cout << "6." << "直接離開" << endl;
        int item_number;
        cin >> item_number;
        item_number = item_number - 1;
        if (item_number == 5)
        {
            return 0;
        }
        else if (account_armor_bag_count[item_number] >= 1)
        {
            armor_bag_count[item_number]++;
            account_armor_bag_count[item_number]--;
            cout << "\t已將" << armor_bag[item_number] << "放進包包" << endl;
        }
        else
        {
            cout << endl << "你的倉庫物品數量不足，請重新選擇" << endl;
            goto re_account_choose_armor;
        }
    }
    else if (ans == "3")
    {
    re_account_choose_food:
        cout << endl << "\t請選擇下列物品放入包包" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "." << food_bag[i] << "\t現在倉庫有:" << account_food_bag_count[i] << "瓶" << endl;
        }
        cout << "6." << "直接離開" << endl;
        int item_number;
        cin >> item_number;
        item_number = item_number - 1;
        if (item_number == 5)
        {
            return 0;
        }
        else if (account_food_bag_count[item_number] >= 1)
        {
            food_bag_count[item_number]++;
            account_food_bag_count[item_number]--;
            cout << "\t已將" << food_bag[item_number] << "放進包包" << endl;
        }
        else
        {
            cout << endl << "你的倉庫物品數量不足，請重新選擇" << endl;
            goto re_account_choose_food;
        }
    }

    return 0;
}
//個人倉庫
int personal_box(int x)
{
    cout << "\t歡迎來到個人倉庫\t\n";
    cout << "---------------------------------------------" << endl;
    cout << "武器欄\n" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arms_bag[i] << "\t數量:" << arms_bag_count[i] << endl;
    }
    cout << "---------------------------------------------" << endl;
    cout << "護甲欄\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << armor_bag[i] << "\t數量:" << armor_bag_count[i] << endl;
    }
    cout << "---------------------------------------------" << endl;
    cout << "藥水欄\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << food_bag[i] << "\t數量:" << food_bag_count[i] << endl;
    }
    cout << "---------------------------------------------" << endl;
    return 0;
}
//帳號倉庫
int account_box(int x)
{
    cout << "\t歡迎來到帳號倉庫\t\n" << endl;
    cout << "請問想要做些什麼" << endl << "1.查看帳號倉庫" << endl << "2.將個人物品放入帳號倉庫" << endl;
    cout << "3.將帳號倉庫物品拿出" << endl << "4.離開帳號倉庫" << endl;
    ifstream account_box;
    account_box.open("accountbox.txt");
    string ans; cin >> ans;
    if (ans == "1")
    {
        cout << "\t歡迎來到帳號倉庫\t\n";
        cout << "---------------------------------------------" << endl;
        cout << "武器欄\n" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << arms_bag[i] << "\t數量:" << account_arms_bag_count[i] << endl;
        }
        cout << "---------------------------------------------" << endl;
        cout << "護甲欄\n" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << armor_bag[i] << "\t數量:" << account_armor_bag_count[i] << endl;
        }
        cout << "---------------------------------------------" << endl;
        cout << "藥水欄\n" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << food_bag[i] << "\t數量:" << account_food_bag_count[i] << endl;
        }
        cout << "---------------------------------------------" << endl;
    }
    else if (ans == "2")
    {
        P2A(0);
    }
    else if (ans == "3")
    {
        A2P(0);
    }
    else if (ans == "4")
    {
        cout << "\n你離開倉庫了\n";
    }
    account_box.close();
    return 0;
}
//武器替換
int arms_change(int x)
{
change_arms_choose:
    int item_have[8], c = 1;
    cout << "你現在裝備的是 " << item[0] << endl;
    cout << "請問你想要換成下列哪件武器呢\n";
    for (int i = 0; i < 8; i++)
    {
        if (arms_bag_count[i] >= 1)
        {
            cout << c << "." << arms_bag[i] << endl;
            item_have[c - 1] = i;
            c++;
        }
    }
    cout << c << "." << "卸下武器" << endl;
    cout << c + 1 << "." << "取消換武器" << endl;
    int ans_choose; cin >> ans_choose;
    if (ans_choose == c)
    {
        for (int i = 0; i < 8; i++)
        {
            if (arms_bag[i] == item[0])
            {
                if (role_type == "戰士")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H - arms_value[i] << endl;
                    cout << "物攻已從\t" << A << "\t變成\t" << A - (arms_value[i] / 2) << endl;
                    H -= (arms_value[i]);
                    A -= (arms_value[i]) / 2;
                    if (H_now >= H)
                    {
                        H_now = H;
                    }
                    Mana(0);
                    if (M_now >= M)
                    {
                        M_now = M;
                    }
                }
                else if (role_type == "法師")
                {
                    cout << "魔攻已從\t" << B << "\t變成\t" << B - arms_value[i] << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D - (arms_value[i] / 2) << endl;
                    B -= arms_value[i];
                    D -= arms_value[i] / 2;
                }
                else if (role_type == "射手")
                {
                    cout << "物攻已從\t" << A << "\t變成\t" << A - arms_value[i] << endl;
                    cout << "速度已從\t" << S << "\t變成\t" << S - (arms_value[i] / 2) << endl;
                    A -= arms_value[i];
                    S -= arms_value[i] / 2;
                }
                else if (role_type == "牧師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H - arms_value[i] << endl;
                    cout << "魔攻已從\t" << B << "\t變成\t" << B - (arms_value[i] / 2) << endl;
                    H -= arms_value[i];
                    B -= (arms_value[i] / 2);
                    if (H_now > H)
                    {
                        H_now = H;
                    }
                    Mana(0);
                    if (M_now > M)
                    {
                        M_now = M;
                    }

                }
                arms_bag_count[i]++;
                cout << "\n已將" << arms_bag[i] << "卸下" << endl;
                item[0] = "無";
                break;
            }
            else if (item[0] == "無")
            {
                cout << "無法卸下武器" << endl;
            }
            return 0;
        }
    }
    else if (ans_choose == c + 1)
    {
        cout << "你已拒絕替換武器" << endl;
        return 0;
    }
    else if (arms_role[item_have[ans_choose - 1]] == role_type)
    {
        arms_bag_count[item_have[ans_choose - 1]]--;
        for (int i = 0; i < 8; i++)
        {
            if (arms_bag[i] == item[0])
            {
                if (role_type == "戰士")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) << endl;
                    cout << "物攻已從\t" << A << "\t變成\t" << A + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2 << endl;
                    H += (arms_value[item_have[ans_choose - 1]] - arms_value[i]);
                    A += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2;
                    if ((arms_value[item_have[ans_choose - 1]] - arms_value[i]) < 0)
                    {
                        if (H_now >= H)
                        {
                            H_now = H;
                        }
                    }
                    else
                    {
                        H_now += (arms_value[item_have[ans_choose - 1]] - arms_value[i]);
                    }
                    Mana(0);
                    if ((arms_value[item_have[ans_choose - 1]] - arms_value[i]) < 0)
                    {
                        if (M_now >= M)
                        {
                            M_now = M;
                        }
                    }
                    else
                    {
                        M_now += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2;
                    }

                }
                else if (role_type == "法師")
                {
                    cout << "魔攻已從\t" << B << "\t變成\t" << B + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2 << endl;
                    B += (arms_value[item_have[ans_choose - 1]] - arms_value[i]);
                    D += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2;
                }
                else if (role_type == "射手")
                {
                    cout << "物攻已從\t" << A << "\t變成\t" << A + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) << endl;
                    cout << "速度已從\t" << S << "\t變成\t" << S + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2 << endl;
                    A += (arms_value[item_have[ans_choose - 1]] - arms_value[i]);
                    S += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2;
                }
                else if (role_type == "牧師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) << endl;
                    cout << "魔攻已從\t" << B << "\t變成\t" << B + (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2 << endl;
                    H += (arms_value[item_have[ans_choose - 1]] - arms_value[i]);
                    B += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) * 2;
                }
                arms_bag_count[i]++;
                cout << "\n已將" << arms_bag[i] << "替換成" << arms_bag[item_have[ans_choose - 1]] << endl;
                item[0] = arms_bag[item_have[ans_choose - 1]];
                break;
            }
            else if (item[0] == "無")
            {
                if (role_type == "戰士")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (arms_value[item_have[ans_choose - 1]]) << endl;
                    cout << "物攻已從\t" << A << "\t變成\t" << A + (arms_value[item_have[ans_choose - 1]] / 2) << endl;
                    H += arms_value[item_have[ans_choose - 1]];
                    A += arms_value[item_have[ans_choose - 1]] / 2;
                    H_now += (arms_value[item_have[ans_choose - 1]] - arms_value[i]);
                    Mana(0);
                    M_now += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) / 2;
                }
                else if (role_type == "法師")
                {
                    cout << "魔攻已從\t" << B << "\t變成\t" << B + (arms_value[item_have[ans_choose - 1]]) << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D + (arms_value[item_have[ans_choose - 1]] / 2) << endl;
                    B += arms_value[item_have[ans_choose - 1]];
                    D += arms_value[item_have[ans_choose - 1]] / 2;
                }
                else if (role_type == "射手")
                {
                    cout << "物攻已從\t" << A << "\t變成\t" << A + (arms_value[item_have[ans_choose - 1]]) << endl;
                    cout << "速度已從\t" << S << "\t變成\t" << S + (arms_value[item_have[ans_choose - 1]] / 2) << endl;
                    A += arms_value[item_have[ans_choose - 1]];
                    S += arms_value[item_have[ans_choose - 1]] / 2;
                }
                else if (role_type == "牧師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (arms_value[item_have[ans_choose - 1]]) << endl;
                    cout << "魔攻已從\t" << B << "\t變成\t" << B + (arms_value[item_have[ans_choose - 1]] / 2) << endl;
                    H += arms_value[item_have[ans_choose - 1]];
                    B += arms_value[item_have[ans_choose - 1]] / 2;
                    H_now += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) * 2;
                    Mana(0);
                    M_now += (arms_value[item_have[ans_choose - 1]] - arms_value[i]) * 2;
                }
                cout << "以幫你將武器替換成" << arms_bag[item_have[ans_choose - 1]] << endl;
                item[0] = arms_bag[item_have[ans_choose - 1]];
                break;
            }
        }
    }
    else
    {
        cout << "你的職業為" << role_type << "無法裝備這把" << arms_bag[item_have[ans_choose - 1]] << endl;
        cout << "職業不符合，沒辦法換取武器" << endl << "請重新替換裝備" << endl;
        goto change_arms_choose;
    }
    return 0;
}
//裝備替換
int armor_change(int x)
{
change_armor_choose:
    int item_have[8], c = 1;
    cout << "你現在裝備的是 " << item[1] << endl;
    cout << "請問你想要換成下列哪件護甲呢\n";
    for (int i = 0; i < 8; i++)
    {
        if (armor_bag_count[i] >= 1)
        {
            cout << c << "." << armor_bag[i] << endl;
            item_have[c - 1] = i;
            c++;
        }
    }
    cout << c << "." << "卸下護甲" << endl;
    cout << c + 1 << "." << "取消換護甲" << endl;
    int ans_choose; cin >> ans_choose;
    if (ans_choose == c)
    {
        for (int i = 0; i < 8; i++)
        {
            if (armor_bag[i] == item[1])
            {
                if (role_type == "戰士")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H - armor_value[i] * 2 << endl;
                    H -= (arms_value[i]) * 2;
                }
                else if (role_type == "法師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H - armor_value[i] << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D - (armor_value[i]) << endl;
                    H -= armor_value[i];
                    D -= armor_value[i];
                }
                else if (role_type == "射手")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H - armor_value[i] << endl;
                    cout << "物防已從\t" << C << "\t變成\t" << C - armor_value[i] << endl;
                    H -= arms_value[i];
                    C -= arms_value[i];
                }
                else if (role_type == "牧師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H - arms_value[i] << endl;
                    cout << "物防已從\t" << C << "\t變成\t" << C - (arms_value[i] / 2) << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D - (arms_value[i] / 2) << endl;
                    H -= arms_value[i];
                    C -= (arms_value[i] / 2);
                    D -= (arms_value[i] / 2);
                }
                armor_bag_count[i]++;
                cout << "\n已將" << armor_bag[i] << "卸下" << endl;
                item[1] = "無";
                if (H_now > H)
                {
                    H_now = H;
                }
                Mana(0);
                if (M_now > M)
                {
                    M_now = M;
                }
                break;
            }
            else if (item[1] == "無")
            {
                cout << "無法卸下護甲" << endl;
            }
            return 0;
        }
    }
    else if (ans_choose == c + 1)
    {
        cout << "你已拒絕替換護甲" << endl;
        return 0;
    }
    else
    {
        armor_bag_count[item_have[ans_choose - 1]]--;
        for (int i = 0; i < 8; i++)
        {
            if (armor_bag[i] == item[1])
            {
                if (role_type == "戰士")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) * 2 << endl;
                    H += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) * 2;
                    if (H_now > H)
                    {
                        H_now = H;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        H_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) * 2;
                    }
                    Mana(0);
                    if (M_now > M)
                    {
                        M_now = M;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        M_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    }
                }
                else if (role_type == "法師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) << endl;
                    H += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    D += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    if (H_now > H)
                    {
                        H_now = H;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        H_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    }
                    Mana(0);
                    if (M_now > M)
                    {
                        M_now = M;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        M_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) * 2;
                    }
                }
                else if (role_type == "射手")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) << endl;
                    cout << "物防已從\t" << C << "\t變成\t" << C + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) << endl;
                    H += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    C += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    if (H_now > H)
                    {
                        H_now = H;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        H_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    }
                    Mana(0);
                    if (M_now > M)
                    {
                        M_now = M;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        M_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) * 3 / 2;
                    }
                }
                else if (role_type == "牧師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) << endl;
                    cout << "物防已從\t" << C << "\t變成\t" << C + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) / 2 << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D + (armor_value[item_have[ans_choose - 1]] - armor_value[i]) / 2 << endl;
                    H += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    C += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) / 2;
                    D += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) / 2;
                    if (H_now > H)
                    {
                        H_now = H;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        H_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]);
                    }
                    Mana(0);
                    if (M_now > M)
                    {
                        M_now = M;
                    }
                    else if ((armor_value[item_have[ans_choose - 1]] - armor_value[i]) > 0)
                    {
                        M_now += (armor_value[item_have[ans_choose - 1]] - armor_value[i]) * 2;
                    }
                }
                armor_bag_count[i]++;
                cout << "\n已將" << armor_bag[i] << "替換成" << armor_bag[item_have[ans_choose - 1]] << endl;
                item[1] = armor_bag[item_have[ans_choose - 1]];
                break;
            }
            else if (item[1] == "無")
            {
                if (role_type == "戰士")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]]) * 2 << endl;
                    H += armor_value[item_have[ans_choose - 1]] * 2;
                    H_now += armor_value[item_have[ans_choose - 1]] * 2;
                    Mana(0);
                    M_now += armor_value[item_have[ans_choose - 1]];
                }
                else if (role_type == "法師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]]) << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D + (armor_value[item_have[ans_choose - 1]]) << endl;
                    H += armor_value[item_have[ans_choose - 1]];
                    D += armor_value[item_have[ans_choose - 1]];
                    H_now += armor_value[item_have[ans_choose - 1]];
                    Mana(0);
                    M_now += armor_value[item_have[ans_choose - 1]] * 2;

                }
                else if (role_type == "射手")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]]) << endl;
                    cout << "物防已從\t" << C << "\t變成\t" << C + (armor_value[item_have[ans_choose - 1]]) << endl;
                    H += armor_value[item_have[ans_choose - 1]];
                    C += armor_value[item_have[ans_choose - 1]];
                    H_now += armor_value[item_have[ans_choose - 1]];
                    Mana(0);
                    M_now += armor_value[item_have[ans_choose - 1]] * 3 / 2;
                }
                else if (role_type == "牧師")
                {
                    cout << "血量已從\t" << H << "\t變成\t" << H + (armor_value[item_have[ans_choose - 1]]) << endl;
                    cout << "物防已從\t" << C << "\t變成\t" << C + (armor_value[item_have[ans_choose - 1]]) / 2 << endl;
                    cout << "魔防已從\t" << D << "\t變成\t" << D + (armor_value[item_have[ans_choose - 1]]) / 2 << endl;
                    H += armor_value[item_have[ans_choose - 1]];
                    C += armor_value[item_have[ans_choose - 1]] / 2;
                    D += armor_value[item_have[ans_choose - 1]] / 2;
                    H_now += armor_value[item_have[ans_choose - 1]];
                    Mana(0);
                    M_now += armor_value[item_have[ans_choose - 1]] * 2;
                }
                cout << "以幫你將護甲替換成" << armor_bag[item_have[ans_choose - 1]] << endl;
                item[1] = armor_bag[item_have[ans_choose - 1]];
                break;
            }
        }
    }
    return 0;
}
//更換裝備
int change_item(int x)
{
re_item:
    cout << "\n請問想要換什麼東西呢\n";
    cout << "1.武器" << endl << "2.裝備" << endl << "3.離開" << endl;
    string ans; cin >> ans;
    if (ans == "1")
    {
        arms_change(0);
        goto re_item;
    }
    else if (ans == "2")
    {
        armor_change(0);
    }
    else if (ans == "3")
    {
        cout << "已離開更換室" << endl << endl;;
        return 0;
    }
    return 0;
}
//倉庫
int storehouse(int x)
{
    cout << "歡迎來到倉庫，請選擇要做的動作" << endl;
    cout << "1.查看個人倉庫" << endl << "2.查看帳號倉庫" << endl << "3.更換角色裝備" << endl << "4.離開倉庫" << endl;
    string ans; cin >> ans;
    if (ans == "1")
    {
        personal_box(0);
    }
    else if (ans == "2")
    {
        account_box(0);
    }
    else if (ans == "3")
    {
        change_item(0);
    }
    else if (ans == "4")
    {
        cout << endl << "你離開了倉庫" << endl << endl;
    }
    return 0;
}
//刪除角色
int delete_role(int x)
{
    string role, trash;
    int c = 0;
    ifstream player3;
    player3.open("player.txt");
    while (player3 >> role)
    {
        if (role == acc)
        {
            player3 >> all_role[c][0] >> all_role[c][1] >> all_able[c][0] >> all_able[c][1] >> all_able[c][2] >> all_able[c][3] >> all_able[c][4] >> all_able[c][5] >> all_able[c][6] >> all_able[c][7];
            for (int i = 0; i < 8; i++)
            {
                player3 >> arms_bag_count2[c][i];
            }
            for (int i = 0; i < 5; i++)
            {
                player3 >> armor_bag_count2[c][i];
            }
            for (int i = 0; i < 5; i++)
            {
                player3 >> food_bag_count2[c][i];
            }
            for (int i = 0; i < 2; i++)
            {
                player3 >> item_count2[c][i];
            }
            player3 >> all_able[c][8];
            c = c + 1;
        }
        else
        {
            for (int i = 0; i < 31; i++)
            {
                player3 >> trash;
            }
        }
    }
    player3.close();
    cout << "\n請選擇你想要刪除的角色\n" << endl;
    for (int i = 0; i < c; i++)
    {
        cout << i + 1 << "." << all_role[i][0] << "\t" << all_role[i][1] << "\t" << all_able[i][0] << " 等" << endl;
    }
    int choose_delete; cin >> choose_delete;
    ifstream player;
    ofstream player2;
    player.open("player.txt");
    player2.open("player2.txt");
    string ac;
    int run_count = 0;
    while (player >> ac)
    {
        if (ac != acc)
        {
            player2 << ac << endl;
            player >> ac;
            player2 << ac << endl;
            player >> ac;
            player2 << ac << " ";
            player >> ac;
            player2 << ac << endl;
            for (int i = 0; i < 7; i++)
            {
                player >> ac;
                player2 << ac << endl;
            }
            for (int i = 0; i < 8; i++)
            {
                player >> ac;
                player2 << ac << " ";
            }
            player2 << endl;
            for (int i = 0; i < 5; i++)
            {
                player >> ac;
                player2 << ac << " ";
            }
            player2 << endl;
            for (int i = 0; i < 5; i++)
            {
                player >> ac;
                player2 << ac << " ";
            }
            player2 << endl;
            for (int i = 0; i < 2; i++)
            {
                player >> ac;
                player2 << ac << " ";
            }
            player2 << endl;
            player >> ac;
            player2 << ac << endl;
        }
        else
        {
            if (choose_delete - 1 != run_count)
            {
                player2 << ac << endl;
                player >> ac;
                player2 << ac << endl;
                player >> ac;
                player2 << ac << " ";
                player >> ac;
                player2 << ac << endl;
                for (int i = 0; i < 7; i++)
                {
                    player >> ac;
                    player2 << ac << endl;
                }
                for (int i = 0; i < 8; i++)
                {
                    player >> ac;
                    player2 << ac << " ";
                }
                player2 << endl;
                for (int i = 0; i < 5; i++)
                {
                    player >> ac;
                    player2 << ac << " ";
                }
                player2 << endl;
                for (int i = 0; i < 5; i++)
                {
                    player >> ac;
                    player2 << ac << " ";
                }
                player2 << endl;
                for (int i = 0; i < 2; i++)
                {
                    player >> ac;
                    player2 << ac << " ";
                }
                player2 << endl;
                player >> ac;
                player2 << ac << endl;

            }
            else
            {
                for (int i = 0; i < 31; i++)
                {
                    player >> ac;
                }
            }
            run_count++;

        }
    }
    player.close();
    player2.close();
    remove("player.txt");
    rename("player2.txt", "player.txt");
    return 0;
}
//金錢回血
int money_Hp(int x)
{
    if (site > 1)
    {
        cout << "\n你必須在城內才能使用此功能" << endl;
        return 0;
    }
    cout << "\n請問你要花費1000元把血及魔力回滿嗎" << endl;
    cout << "\n1.是" << endl << "2.否" << endl;
    int ans; cin >> ans;
    if (ans == 1)
    {
        if (money >= 1000)
        {
            H_now = H;
            M_now = M;
            money -= 1000;
            cout << "\n已將你的血量及魔力回滿了" << endl;
        }
        else
        {
            cout << "\n你的金錢不夠，血量及魔力沒有變化" << endl;
        }
    }
    else
    {
        cout << "\n已離開回復商店" << endl;
    }
    return 0;
}
//大廳
int hall(int x)
{
    saving(0);
    cout << endl;
    if (x != 1)
    {
        cout << "歡迎來到大廳" << endl;
        cout << "請選擇你想要做的事" << endl;
    }
    else
    {
        cout << "請繼續選擇你想要做的事" << endl << endl;
    }
    cout << "1.存檔" << endl << "2.戰鬥" << endl << "3.包包及倉庫" << endl << "4.移動" << endl << "5.顯示角色屬性" << endl << "6.商店" << endl << "7.使用藥水" << endl << "8.登出" << endl << "9.回復商店" << endl << "10.離開遊戲" << endl;
    string ans;
    cin >> ans;
    if (ans == "1")
    {
        saving(0);
    }
    else if (ans == "2")
    {
        fighting(0);
    }
    else if (ans == "3")
    {
        storehouse(0);
    }
    else if (ans == "4")
    {
        map(0);
    }
    else if (ans == "5")
    {
        role_list(0);
    }
    else if (ans == "6")
    {
        shop(0);
    }
    else if (ans == "7")
    {
        food_use(0);
    }
    else if (ans == "8")
    {
        cout << "\n以登出\n";
        last_account(0);
        re_start:
        cout << "請輸入數字來選擇您想要執行的動作" << endl;
        cout << "1.創建新遊戲" << endl;
        cout << "2.繼續遊戲" << endl;
        cout << "3.刪除角色資料" << endl;
        cout << "4.離開遊戲" << endl;

        string start_num;
        cin >> start_num;

        if (start_num == "1")
        {
            new_world(0);
        }
        else if (start_num == "2")
        {
            int ans_load;
            ans_load = load_world(0);
            if (ans_load == 1)
            {

                enter_type(0);
                system("cls");
                new_world(1);
            }
            cout << "在你離開的期間血量及魔力已經回滿" << endl;
        }
        else if (start_num == "3")
        {
            delete_role(0);
            goto re_start;
        }
        else if (start_num == "4")
        {
            cout << "感謝遊玩" << endl;
            return 4;
        }
        else
        {
            cout << "Error_choose_world" << endl;
        }
        H_now = H;
        Mana(0);
        M_now = M;
        site = 1;
        hall(0);
    }
    else if (ans == "9")
    {
        money_Hp(0);
    }
    else if (ans == "10")
    {
        cout << "感謝遊玩" << endl;
    }
    else if (ans == "money")
    {
        int m; cin >> m;
        money += m;
    }
    else
    {
        cout << "Error_in_hall" << endl;
    }
    if (ans != "10")
    {
        hall(1);
    }
    return 0;
}
//主程式
int main()
{


    cout << "歡迎進入RPG" << endl;
    cout << "請問要創建帳號還是直接登入呢" << endl;
    cout << "1.創建帳號" << endl;
    cout << "2.直接登入" << endl;

    string in;
    string in2;
    cin >> in;
    if (in == "1")
    {
        system("cls");
        in2 = new_account(0);
        if (in2 == "2")
        {
            last_account(0);
        }

    }
    else if (in == "2")
    {
        system("cls");
        in2 = last_account(0);
        if (in2 == "2")
        {
            last_account(0);
        }
        else if (in2 == "3")
        {
            find_account(acc);
            last_account(0);
        }
    }
    else
    {
        cout << "Error_main_acc" << endl;
        return 0;
    }
    re_start:
    cout << "請輸入數字來選擇您想要執行的動作" << endl;
    cout << "1.創建新遊戲" << endl;
    cout << "2.繼續遊戲" << endl;
    cout << "3.刪除角色資料" << endl;
    cout << "4.離開遊戲" << endl;

    string start_num;
    cin >> start_num;

    if (start_num == "1")
    {
        new_world(0);
    }
    else if (start_num == "2")
    {
        int ans_load;
        ans_load = load_world(0);
        if (ans_load == 1)
        {

            enter_type(0);
            system("cls");
            new_world(1);
        }
        cout << "在你離開的期間血量及魔力已經回滿" << endl;
    }
    else if (start_num == "3")
    {
        int leave_hall;
        leave_hall=delete_role(0);
        if (leave_hall==4)
        {
            return 0;
        }
        goto re_start;
    }
    else if (start_num == "4")
    {
        cout << "感謝遊玩" << endl;
        return 0;
    }
    else
    {
        cout << "Error_choose_world" << endl;
    }
    H_now = H;
    Mana(0);
    M_now = M;
    site = 1;
    hall(0);

    return 0;
}