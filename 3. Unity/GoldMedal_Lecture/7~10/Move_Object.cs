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


    Vector3 target = new Vector3(8, 1.5f, 0);
    // Update is called once per frame
    void Update()
    {
        Vector3 vec = new Vector3(
            Input.GetAxisRaw("Horizontal") * Time.deltaTime,
            Input.GetAxisRaw("Vertical") * Time.deltaTime,
            0);  // ���� ��

        transform.Translate(vec);
        //translate : ���Ϳ� ���ϱ� 
        // vector �Լ� : �ð� �Ű������� ���ϱ�


        //1. MoveToward�� ����Ͽ� �̵��ϴ� ���
        //transform.position = Vector3.MoveTowards(transform.position, target, 1f);// ���� ��ġ, ��ǥ ��ġ, �ӵ� �� �����Ǿ� �ֽ��ϴ�.


        //2. SmoothDamp�� ����Ͽ� �̵��ϴ� ���
        //Vector3 velo = Vector3.zero;
        //transform.position = Vector3.SmoothDamp(transform.position, target, ref velo, 0.1f);//�ε巯�� ���� �̵�

        //3. Lerp (���� ����)
        /*transform.position =
            Vector3.Lerp(transform.position, target, 0.05f); //������ �Ű������� ����ϰ� �ӵ� ����(�ִ� 1)*/

        //4. SLerp (���� ���� ����) - ������ �̵�
        /*transform.position =
            Vector3.Slerp(transform.position, target, 0.05f);*/
    


    }
}
