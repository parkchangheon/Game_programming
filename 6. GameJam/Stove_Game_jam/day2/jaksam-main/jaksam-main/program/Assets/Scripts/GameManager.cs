using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager gm;
    public gamescene gamescene;
    public Timer timer;
    float health_gage = 125f;
    float health_max = 200f;
    public int stageIndex = 2;
    public GameObject[] Junk;
    public int[] junkCount;
    public int[] junkLevel;

    public GameObject[] Health;
    public int[] healthCount;
    public int[] healthLevel;

    public Move_Player player;
    public Transform playerTrans;

    public float Gauge_Amount()
    {
        return health_gage / health_max;
    }


    private void Awake()
    {
        gm = this;

        player = GameObject.FindGameObjectWithTag("Player").GetComponent<Move_Player>();
        playerTrans = player?.transform;
 
        //var JunkFood = new List<string>();
        //var HealthFood = new List<string>();

        //HealthFood.Add("������");
        //HealthFood.Add("�ñ�ġ");
        //HealthFood.Add("����");
        //HealthFood.Add("����ũ");
        //HealthFood.Add("���");

        //JunkFood.Add("ĵ��1");
        //JunkFood.Add("ĵ��2");
        //JunkFood.Add("������Ű");
        //JunkFood.Add("�ܹ���");
        //JunkFood.Add("�����̼ҽ���");
        //JunkFood.Add("�������");
        //JunkFood.Add("���");
        //JunkFood.Add("����Ƣ��");
        InvokeRepeating(nameof(JunkCreate), 0.5f, 0.5f);
        InvokeRepeating(nameof(HealthCreate), 0.5f, 0.5f);
    }

    public void JunkCreate()
    {
        int i = Random.Range(0, Junk.Length);
        if (junkCount[i] < 1 || junkLevel[i] < stageIndex)
        {
            return;
        }          
        

        GameObject go = Instantiate(Junk[i]);
        go.GetComponent<FoodObject>().idx = i;

        Vector3 p = Random.onUnitSphere;
        p.z = 0f;
        go.transform.position = playerTrans.position + p.normalized * 7f;
        junkCount[i]--;
    }

    public void HealthCreate()
    {
        int i = Random.Range(0, Health.Length);
        if (healthCount[i] < 1 || healthLevel[i] < stageIndex)
        {
            return;
        }

        GameObject go = Instantiate(Health[i]);
        go.GetComponent<FoodObject>().idx = i;

        Vector3 p = Random.onUnitSphere;
        p.z = 0f;
        go.transform.position = playerTrans.position + p.normalized * 5f;
        healthCount[i]--;
    }

    private void Start()
    {

    }
    void Update()
    {
        // ĳ���� ��������  
        // �ִϸ��̼� �ٲ��ְ�, ������ Ǫ�� �ٲ��ְ�

        if (gm.health_gage >= 200) // ���� (3�ܰ�) 
        {
            Debug.Log("���� ����");
            gamescene.EndingCutScene(-1);
        }

        else if (gm.health_gage <= 0) // clear 
        {
            Debug.Log("���� �¸�");
            gamescene.EndingCutScene((int)timer.time);
        }
    }


    public void SetGuage(float value)
    {
        health_gage += value;

        if (health_gage <= 50)
            stageIndex = 1;
        else if (health_gage <= 150)
            stageIndex = 2;
        else if (health_gage <= 200)
            stageIndex = 3;

        if(value < 0)
        {
            player.SetHeal();


        }
        player.Fat((int)health_gage);
    }

    public void FoodOff(FoodObject food)
    {
        if (food.foodType == FOOD_TYPE.JUNK)
        {
            junkCount[food.idx]++;
        }
        else
        {
            healthCount[food.idx]++;
        }
    }
}