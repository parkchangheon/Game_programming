using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour

    //prefab�� ��������� �� �� �ִ� (generator ��)  ==> ���� / �跰 ����
{
    // Start is called before the first frame update

    public float speed;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position += Vector3.left * speed * Time.deltaTime;    //vector3.left=(-1,0,0) �� ���Ѵ�    // Time.deltatime�� ���� DeltaTime�� ����

    }
}
