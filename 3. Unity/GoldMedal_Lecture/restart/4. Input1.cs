using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeCycle : MonoBehaviour
{

    /*    //1. �ʱ�ȭ ���� -> ���� ���� -> ���� ���� -> ����
        //             Ȱ��ȭ                    ��Ȱ��ȭ

        // 1. �ʱ�ȭ ����

        // ���� ������Ʈ�� ���ȿ� ������ �����ѹ��� ���� ���� ����ȴ�. ��ġ �����ڿ� ���� ����?
        private void Awake()
        {
            Debug.Log("�÷��̾� �����Ͱ� �غ�Ǿ����ϴ�.");
        }

        // Awake ���ٴ� ������, Start ���ٴ� ������ ����Ǵ� �κ� ==> Ȱ��ȭ ����
        private void OnEnable()
        {
            Debug.Log("�÷��̾� �α���");
        }

        // ������Ʈ ���� ���� ���� ����
        private void Start()
        {
            Debug.Log("��� ��� ì����ϴ�.");
        }


        // 2. ���� ���� ����

        // ���� ������ �ϱ� ���� ����Ǵ� �Լ�
        private void FixedUpdate() // ������ �ֱ�� ���� -> CPU ���ϰ� ����.
        {
            Debug.Log("�̵�");
        }


        // 3. ���� ���� ����

        // ���� �ֱⰡ ������ �� �ִ�.
        private void Update()
        {
            Debug.Log("���� ���");
        }

        // ��� ������Ʈ ������ ��ó��
        private void LateUpdate()
        {
            Debug.Log("����ġ ȹ��");
        }

        //��Ȱ��ȭ �κ�
        private void OnDisable()
        {
            Debug.Log("�÷��̾� �α׾ƿ�");
        }

        // 4. ���� ����
        private void OnDestroy() //�����ɶ�
        {
            Debug.Log("�÷��̾� �����͸� �����Ͽ����ϴ�.");
        }*/



    //=============================B6 ���� ===============================

    //�Է��� 3������ �����Ǿ��ִµ�, down, stay, up ���� �����Ǿ� �ִ�.

    /*    private void Update()
        {
            //input�� ���� �� �Է��� ��� �����Ѵ�.
            if (Input.anyKeyDown)  //������Ƽ
                Debug.Log("�÷��̾ �ƹ�Ű�� �������ϴ�.");

            *//*if (Input.anyKey)  //���������� ���.
                Debug.Log("Ű�� ������ �ֽ��ϴ�.");*//*

            if (Input.GetKeyDown(KeyCode.Return))  //Enter�� Return�̴�.
                Debug.Log("�������� �����Ͽ����ϴ�.");

            if (Input.GetKeyDown(KeyCode.LeftArrow))
                Debug.Log("���ʹ���Ű�� �������ϴ�.");

            if (Input.GetKeyDown(KeyCode.RightArrow))
                Debug.Log("������ ����Ű�� �������ϴ�.");

            if (Input.GetKeyUp(KeyCode.RightArrow))
                Debug.Log("������ ����Ű�� �½��ϴ�.");


            // 0�� ���콺 ���� ��ư, 1�� ������ ��ư
            if (Input.GetMouseButtonDown(0))
                Debug.Log("�̻��� �߻�");

            if (Input.GetMouseButton(0))
                Debug.Log("�̻��� ������ ��!!");

            if (Input.GetMouseButtonUp(0))
                Debug.Log("���۹̻��� �߻�!!");
        }*/




    //==========axis Ȱ��============
    /*    private void Update()
        {
            if (Input.GetButtonDown("Jump"))
                Debug.Log("����");

            if(Input.GetButton("Horizontal"))
            {
                Debug.Log("Ⱦ �̵� ��" + Input.GetAxis("Horizontal"));

                //Debug.Log("Ⱦ �̵� ��" + Input.GetAxisRaw("Horizontal")); => -1, 1, 0 ������ ǥ��
            }

            if(Input.GetButton("Vertical"))
            {
                Debug.Log("�� �̵� ��" + Input.GetAxisRaw("Vertical"));
            }


        }*/





    //========���� �̵�================

    private void Start()
    {
        int number = 4; //��Į�� (��)
        //Vector3 vec = new Vector3(5, 0, 0); //���Ͱ�(�������)
        //transform.Translate(vec);  //��ġ�� �����ش�.
    }

    private void Update()
    {
        Vector3 vec = new Vector3(
            Input.GetAxisRaw("Horizontal"),
            Input.GetAxisRaw("Vertical"),
            0);
        transform.Translate(vec);
    }

}
