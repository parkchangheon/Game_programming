using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Oscillation : MonoBehaviour
{

    Vector3 startingPosition;
    [SerializeField] Vector3 movementVector;
    [SerializeField] [Range(0,1)]float movementFactor;
    [SerializeField] float period = 2f;
    void Start()
    {
        startingPosition = transform.position;
        Debug.Log(startingPosition);
    }

    void Update()
    {
        if (period <=Mathf.Epsilon) // �ſ� ���� ���϶�.
            return;

        float cycles = Time.time / period;  //�ð��� �þ�� ���� ��� ���� / period
        
        const float tau = Mathf.PI * 2;     // 2��
        float rawSinWave = Mathf.Sin(cycles * tau); //sin ��

        movementFactor = (rawSinWave + 1f) / 2f;   //-1 ~ 1�̴��� 0 ~ 2�� �ٲٰ� 0~1�� �ٽñ� ����ȭ ��Ŵ

        Vector3 offset = movementVector * movementFactor;
        transform.position = startingPosition + offset;
    }
}
