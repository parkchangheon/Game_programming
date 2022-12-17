using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WayPoint : MonoBehaviour
{
    [SerializeField] GameObject towerPrefab;
    [SerializeField] bool isPlaceable;

    void OnMouseDown()
    {
        if(isPlaceable)
        {
            Instantiate(towerPrefab, transform.position, Quaternion.identity); //���� ���� ���߿� ������Ʈ�� ������ �� �ִ�. (�����ϰ��� �ϴ� ������Ʈ, ��ġ, ȸ���� ���� default identity)
            isPlaceable = false;
        }
            
    }

    
    
}
