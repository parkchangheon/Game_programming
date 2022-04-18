using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Hello Unity");


        // 1. ��������
        int level = 5;
        float strength = 15.5f;
        string playername ="���˻�";
        bool isFullLevel = false;

        Debug.Log("����� �̸���?");
        Debug.Log(playername);
        Debug.Log("����� ������??");
        Debug.Log(level);


        // 2. �׷��� ����
        // �迭
        string[] monster = { "������", "�縷��", "�Ǹ�" };
        for(int i = 0; i < 3; i++)
        {
            Debug.Log(monster[i]);
        }


        int[] monsterlevel = new int[3];  // �����Ҵ�
        monsterlevel[0] = 1;
        monsterlevel[1] = 2;
        monsterlevel[2] = 3;

        Debug.Log("�ʿ� �����ϴ� ������ ����");
        for (int i = 0; i < 3; i++)
        {
            Debug.Log(monsterlevel[i]);
        }


        // ����Ʈ
        List<string> items = new List<string>(); //���׸�?
        items.Add("���� ����");
        items.Add("������ ����");

        items.RemoveAt(0); //�ش� ��ġ ������ ����

        Debug.Log(items[0]);



        // 3. ������
        int exp = 1500;
        exp = 1500 + 320;
        exp -= 10;
        level = exp / 300;
        strength = level * 3.1f;


        int nextExp = 300 - (exp % 300);
        Debug.Log("���� �������� ���� ����ġ��? ");
        Debug.Log(nextExp);

        int fullLevel = 30;
        isFullLevel = level == fullLevel;
        Debug.Log("���� �����Դϱ�? " + isFullLevel);
        bool isEndTutorial = level > 10;
        Debug.Log("Ʃ�丮���� ���� ����Դϱ�? " + isEndTutorial);

        int health = 30;
        int mana = 25;
        bool isBadCondition = health <= 50 && mana <= 20;
        Debug.Log("����� ���°� ���޴ϱ�? " + isBadCondition);

        string condition = isBadCondition ? "����" : "����";
        Debug.Log("����� ���°� ���޴ϱ�?" + condition);



        // 4. Ű����


        // 5. ���ǹ� 
        if (condition == "����")
            Debug.Log("����� ���°� ���ڴ�.");
        else
            Debug.Log("���´� �������� �ʾҴ�.");

        if (isBadCondition && items[0] == "������ ����")
        {
            health += 20;
            Debug.Log("������ ������ ����߽��ϴ�.");
        }
        else if (isBadCondition && items[0] == "���� ����")
        {
            mana += 20;
            Debug.Log("������ ������ ����߽��ϴ�.");
        }


        switch(monster[0])
        {
            case "������":
            case "�з�":
                Debug.Log("�������̴�!!");
                break;

            case "�縷��":
                Debug.Log("�縷���̴�!!!");
                break;

            case "�Ǹ�":
                Debug.Log("�Ǹ������̴�!!!");
                break;

            default:
                Debug.Log("�� �� ���� ���� ����!!");
                break;
        }



        // 6. �ݺ���
        while (health>0)
        {
            health--;
            if (health > 0)
                Debug.Log("�� �������� �Ծ����ϴ�." + health);
            else
                Debug.Log("����Ͽ����ϴ�.");

            if (health == 10)
            {
                Debug.Log("�ص����� ����ߴ�.");
                break;
            }
        }

        for(int count = 0; count < 10; count++)
        {
            health++;
            Debug.Log("�ش�� ġ����..." + health);
        }

        for(int count=0;count<monster.Length;count++)
        {
            Debug.Log("�� ������ �ִ� ���� : " + monster[count]);
        }

        foreach (string m in monster)
        {
            Debug.Log("���͵��� �̸��� " + m);
        }



        // 7. �Լ� (�޼ҵ�)
        health = Heal(health);

        for(int i=0;i<monster.Length;i++)
        {
            Debug.Log(Battle(monsterlevel[i], level));
        }




        // 8. Ŭ���� 
        Actor player = new Actor();  //�ν��Ͻ�ȭ (Ŭ������ ����ȭ ��Ű�� ��)
        player.name = "�ھ�ó";
        player.level = 50;
        Debug.Log(player.name + "�� ������ " + player.level + " �Դϴ�.");

    }

    // Update is called once per frame
    void Update()
    {
        
    }


    //���� �޴� �Լ�
    int Heal(int Chealth)
    {
        Chealth += 10;
        Debug.Log("���� �޾ҽ��ϴ�. " + Chealth);
        return Chealth;
    }

    string Battle(int mon, int lev)
    {
        if (mon > lev)
            return "����";

        else
            return "�̰��.";
    }


}
