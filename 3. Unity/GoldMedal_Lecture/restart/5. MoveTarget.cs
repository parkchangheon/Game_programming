using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveTarget : MonoBehaviour
{
    Vector3 target = new Vector3(8, 1.5f, 0);
    void Update()
    {
        // 1. movetowards
        //transform.position = Vector3.MoveTowards(transform.position, target, 1f);  //������ġ, Ÿ����ġ, �ӵ� 

        // 2. SmoothDamp
        /*Vector3 velo = Vector3.zero;
        //Vector3 velo = Vector3.up*50; //�߾Ⱦ�

        transform.position = Vector3.SmoothDamp(transform.position, target, ref velo, 0.1f);   //���� -> �ǽð����� �ٲ�� �� ���� ���� ref*/

        // 3. Lerp (����) - Smooth Damp���� ���ӽð��� ���.
        //transform.position = Vector3.Lerp(transform.position, target, 0.05f); // ���� ���� �ټ��� ������ �̵�

        // 4. SLerp (���� ���� ����) - ȣ�� �׸��� �̵�
        //transform.position = Vector3.Slerp(transform.position, target, 0.05f); // ������ �̵� -> �����ϴ� ���� ������
    }
}
