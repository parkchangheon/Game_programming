using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; //�־��ش�

public class Score : MonoBehaviour
{
    public static int score=0; //static �� Ŭ�������� �����ϴ� ���� //Ŭ���� �ۿ����� �����ؼ� ������ ����
    public static int best_score = 0;
    // Start is called before the first frame update
    void Start()
    {
        score = 0;
        
    }

    // Update is called once per frame
    void Update()
    {
        //�ؽ�Ʈ ��Ҹ� �����´�
        GetComponent<Text>().text = score.ToString();
        if (Score.score > Score.best_score)
            Score.best_score = Score.score;
    }

    //Unity boxColider���� => collision �⺻�� �������̰�, Trigger�� ������ �����ϴ�
}
