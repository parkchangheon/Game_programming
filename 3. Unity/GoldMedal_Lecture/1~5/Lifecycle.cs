using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Lifecycle : MonoBehaviour
{
    void Awake() // Awake �Լ��� �����Ҷ� �ѹ��� ����Ǵ� ���� Ư¡�̴�.
    {
        Debug.Log("Ǯ���̾� �����Ͱ� �غ�Ǿ����ϴ�.");
    }

    private void OnEnable() // ���� ������Ʈ�� Ȱ��ȭ �Ǿ�����
    {
        Debug.Log("�÷��̾� �α���");

    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("������ ì����ϴ�");
    }

    private void FixedUpdate() // ���������� �ϱ����� �ϴ� Update�ϴ� �Լ�
    {
        //������ �ֱ�� CPU�� �����.
        Debug.Log("�̵��Ѵ�."); // ��� �����ϰ� �ִ�. 
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("���ͻ��");
    }


    void LateUpdate() // ��� ������Ʈ�� ���� �ڿ� ������ �ȴ�.
    {
        Debug.Log("����ġ ȹ�� ");
    }

    private void OnDisable()
    {
        Debug.Log("Ǯ���̾� �α׾ƿ�.");

    }

    private void OnDestroy() // ������Ʈ�� �����ɶ� ���ȴ�
    {
        Debug.Log("Ǯ���̾� �����Ͱ� �����Ǿ����ϴ�.");

    }
}
