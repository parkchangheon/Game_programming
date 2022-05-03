using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MyBall : MonoBehaviour
{

    Rigidbody rigid;

    void Start()
    {
        rigid = GetComponent<Rigidbody>();
        //rigid.velocity = Vector3.right; //�ӷ��� �־���.����������
        //rigid.velocity = new Vector3(2, 4, 3);

        //������ �б�
        //rigid.AddForce(Vector3.up * 5, ForceMode.Impulse); // ����


    }

    //unity������ rigid velocity�� FixedUpdate�� ���ִ� ���� �����Ѵ�.
    private void FixedUpdate()
    {
        //rigid.velocity = new Vector3(2, 4, 3);
/*        if (Input.GetButtonDown("Jump"))
            rigid.AddForce(Vector3.up * 50, ForceMode.Impulse);*/

        //Vector3 vec = new Vector3(Input.GetAxisRaw("Horizontal"), 0, Input.GetAxisRaw("Vertical")); //���ʹ� Ŭ���� �� �� ���δ� x
        //rigid.AddForce(vec*(0.2f), ForceMode.Impulse);  // impulse -> forcemode

        //ȸ����
        //rigid.AddTorque(Vector3.back);
        float h = Input.GetAxisRaw("Horizontal");
        float v = Input.GetAxisRaw("Vertical");
        Vector3 vec = new Vector3(h, 0, v);

        rigid.AddForce(vec, ForceMode.Impulse);
    }


    private void OnTriggerStay(Collider other)
    {
        if (other.gameObject.name == "Cube")
        {
            rigid.AddForce(Vector3.up * 2, ForceMode.Impulse);
        }
    }

    void Update()
    {
        //���⿡ rigid.velocity�� �ָ� ��� ���ư�����?
        //rigid.velocity = new Vector3(2, 4, 3); // ���ּ� ���� ���ư���.


    }
}
