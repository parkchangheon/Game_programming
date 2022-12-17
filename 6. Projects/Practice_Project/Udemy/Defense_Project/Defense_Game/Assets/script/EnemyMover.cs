using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMover : MonoBehaviour
{
    [SerializeField] List<WayPoint> path = new List<WayPoint>();
    [SerializeField] [Range(0f, 5f)] float speed = 1f;

    void Start()
    {
        StartCoroutine(FollowPath());
    }

    IEnumerator FollowPath()
    {
        foreach(WayPoint waypoint in path)
        {
            Vector3 startPosition = transform.position;
            Vector3 endPosition = waypoint.transform.position;
            float travelPercent = 0f;

            transform.LookAt(endPosition); //�����ϰ� �ִ� ������ �ٶ󺸵��� ó��

            while(travelPercent < 1f) { //0~1�� �¾�
                travelPercent += (Time.deltaTime * speed); //1������ ������
                transform.position = Vector3.Lerp(startPosition, endPosition, travelPercent); // ���� ���� -> ������, ����, ��� ������ ��ġ����.
                yield return new WaitForEndOfFrame(); //1������ ������, yield return
            }
        }
    }
}
