using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MakePipe : MonoBehaviour
{

    public GameObject pipe;    //prefab�̵� ������ ������Ʈ�� ���� ���� �� �ִ�.(�Ʊ� ����)
    public float timeDiff;
    float Timer=0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Timer += Time.deltaTime;
        if(Timer>timeDiff)
        {
            GameObject newpipe = Instantiate(pipe); //������ ���� ������ ��ü�� ���Ŷ�
            newpipe.transform.position = new Vector3(3, Random.Range(-3.0f,3.1f), 0);
            Timer = 0;
            Destroy(newpipe,6);
        }
    }
}
