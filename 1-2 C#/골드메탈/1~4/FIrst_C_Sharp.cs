using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FIrst_C_Sharp : MonoBehaviour  // ��� �����̺��� ���...
{
    // Start is called before the first frame update
    void Start()
    {

        // �ּ��� �޾��ش�.
        Debug.Log("Warning Chang is Back");

        int level=5;
        float strength=15.5f;
        string playerName="Sean";
        bool isFullLevel=false;


        /*Debug.Log("����� �̸���");
        Debug.Log(playerName);

        Debug.Log("������ ???");
        Debug.Log(level);

        Debug.Log("����� ����?");
        Debug.Log(strength);

        Debug.Log("�����ΰ�??");
        Debug.Log(isFullLevel);

        //2. �׷��� ���� 
        string[] arr = { "������", "�縷��", "�Ǹ�" };
        int[] monsterLevel = new int[3];
        monsterLevel[0] = 1;
        monsterLevel[1] = 3;
        monsterLevel[2] = 10;

        for (int i = 0; i < 3; i++)
        {
            Debug.Log(arr[i] + monsterLevel[i]);

        }


        //3. ����Ʈ.

        List<string> items = new List<string>();
        items.Add("������ 30"); //����
        items.Add("���� ���� 30");
        items.Add("���� ���� 30");

        Debug.Log(items[0]);

        items.RemoveAt(1); // Ư�� �������� �����Ѵ�. 
        for (int i = 0; i < items.Count; i++) // .Count ����Ʈ ũ�� �����ش�.
        {
            Debug.Log(items[i]);
        }


        //3. ������
        int exp = 1500;

        exp += 20;
        level = exp / 100;
        strength = level * 3.1f;

        Debug.Log(exp);
        Debug.Log(level);
        Debug.Log(strength);


        //4. �� ������ 
        bool flag;
        int health = 100;
        int mana = 5;

        flag = health <= 50 && mana <= 20;
        Debug.Log(flag);
        


        //5. ���ǹ�
        if (level == 1)
        {
            Debug.Log("������ 1������ �ȳ��´�");
        }
        else
        {
            Debug.Log("���� �Ӿ���???");
        }

        switch (level)
        {
            case 1:
                Debug.Log("1�̴�");
                break;
            case 2:
                Debug.Log("2�̴�");
                break;
            case 3:
                Debug.Log("3�̴�");
                break;
            case 4:
                Debug.Log("4�̴�");
                break;
            case 5:
                Debug.Log("5�̴�");
                break;
            default:
                Debug.Log("5�� �Ѿ���.");
                break;
        }

        




        //6. �ݺ���

        while (level<=5)
        {
            Debug.Log(level);
            level+=1;
        }

        for(int i = 0; i < 10; i++)
        {
            level++;
        }
        Debug.Log(level);

        //�׷� �� ���� ����!!!!!!!!!!!!!!========================
        // �迭�� ���, .Length �̰�, ����Ʈ �� ��� .Count�� ������ش�.
        string[] arr = { "������", "�縷��", "�Ǹ�" };
        foreach(string monster in arr)
        {
            Debug.Log("���ʹ� "+monster);
        }
        
        int health = 100;
        health=Heal(health);
        int[] monsterLevel = new int[3];
        monsterLevel[0] = 1;
        monsterLevel[1] = 3;
        monsterLevel[2] = 10;

        for (int i = 0; i < monsterLevel.Length; i++)
        {
            result(level, monsterLevel[i]);
        }
        */


        //8. Ŭ���� ����ϱ�
        // ������Ʈ ���Ͽ� c# ��ũ��Ʈ �����, �ű�ٰ� Ŭ���� �����,
        Actor player = new Actor(); // �ν��Ͻ�ȭ
        Debug.Log(player.move());



    }

    //7. �Լ�(�޼ҵ�)
    int Heal(int current_health)
    {
        current_health += 10;
        Debug.Log("���� �޾ҽ��ϴ�." + current_health);
        return current_health;
    }

    void result(int hero, int monster)
    {
        if (hero > monster)
            Debug.Log("������ �̰���ϴ�.");
        else
            Debug.Log("������ �̰���ϴ�.");
    }


    // Update is called once per frame
    void Update()
    {
        
    }
}
