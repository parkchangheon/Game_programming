using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move_Object : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //���� ������Ʈ Ʈ�������� �̹� 1:1 ����� ����Ǿ, ������ �ʿ����.
        Vector3 vec = new Vector3(0, 0, 0);  // ���� ��
        transform.Translate(vec);  // �ܼ� �̵�(������ ũ�� ��ŭ)


    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vec = new Vector3(
            Input.GetAxisRaw("Horizontal"),
            Input.GetAxisRaw("Vertical"), 
            0);  // ���� ��

        transform.Translate(vec);
        
    }
}
