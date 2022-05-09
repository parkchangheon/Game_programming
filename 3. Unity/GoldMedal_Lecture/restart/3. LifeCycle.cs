using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeCycle : MonoBehaviour
{

    //1. �ʱ�ȭ ���� -> ���� ���� -> ���� ���� -> ����
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
    }



}
