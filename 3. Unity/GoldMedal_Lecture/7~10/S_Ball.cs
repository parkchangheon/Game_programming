using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class S_Ball : MonoBehaviour
{

    Rigidbody rigid;

    void Start()
    {
        /*rigid = GetComponent<Rigidbody>(); */  //rigid �ٵ� �ʱ�ȭ 
                                             //rigid.velocity = Vector3.right;
                                             //rigid.velocity = new Vector3(2, 4, 3); // ���� Ƣ����� ����. => �� ������ ���͸��� ��������

        //������ �е��� ȿ���� �ִ� ��
    }

    void Update()
    {
        // ������Ʈ�� rigid ���� ���� �� ����, ��� �� ���ư���.
        // rigidbody ���� �ڵ�� Fixed Update�� �־ �۵����Ѷ�

        /*if (Input.GetButtonDown("Jump"))
        {
            rigid.AddForce(Vector3.up * 50, ForceMode.Impulse);
            Debug.Log(rigid.velocity);
        }

        Vector3 vec = new Vector3(Input.GetAxisRaw("Horizontal"), 
            0,Input.GetAxisRaw("Vertical"));

        rigid.AddForce(vec, ForceMode.Impulse);*/

        //3. ȸ����
        //rigid.AddTorque(Vector3.back); // vec�� ������ ��´�.
    }

}
