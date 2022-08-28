using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterLifeCycle : MonoBehaviour
{
    public bool IsHit;
    public bool IsHit2;
    // Start is called before the first frame update
    void Start()
    {
        IsHit = false;
        IsHit2 = false;
    }

    // Update is called once per frame
    void Update()
    {
        IsHit = GameObject.Find("BtnLeft").GetComponent<ButtonLogic>().CollideWith;   //�¾������� true�� �ȴ�. �̶� ����
        IsHit2 = GameObject.Find("BtnRight").GetComponent<ButtonLogic>().CollideWith;

        if ((IsHit || IsHit2)) //����
        {
            if (IsHit && IsHit2)
                StartCoroutine(SpawnAndDestroy());
            else if (()||())
                StartCoroutine(SpawnAndDestroy());
        }
    }

    IEnumerator SpawnAndDestroy()
    {
        yield return new WaitForSeconds(0.2f);
        Destroy(gameObject);
        GameObject.Find("MonsterSpawner").GetComponent<MonsterSpawn>().Spawn();
    }

}
