using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Enemy))]
public class EnemyMover : MonoBehaviour
{
    [SerializeField] [Range(0f, 5f)] float speed = 1f;

    List<Node> path = new List<Node>();

    Enemy enemy;
    GridManager gridManager;
    PathFinder pathFinder;

    void Awake()
    {
        enemy = GetComponent<Enemy>();
        gridManager = FindObjectOfType<GridManager>();
        pathFinder = FindObjectOfType<PathFinder>();
    }

    //life cycle -> awake => onenable => reset => start => fixedUpdate => update =>lateUpdate
    void OnEnable()
    {
        FindPath();
        ReturnToStart();
        StartCoroutine(FollowPath());
    }

    void FindPath()
    {
        path.Clear();
        path = pathFinder.GetnewPath();
        /*GameObject parent = GameObject.FindGameObjectWithTag("Path");
        foreach(Transform child in parent.transform)
        {
            Tile wayPoint = child.GetComponent<Tile>();

            if(wayPoint != null)
            {
                path.Add(wayPoint);
            }
        }*/
    }

    void ReturnToStart()
    {
        /*transform.position = path[0].transform.position;*/
        transform.position = gridManager.GetPositionFormCoordinates(pathFinder.StartCoordinates);
    }

    void FinishPath()
    {
        enemy.StealGold();
        gameObject.SetActive(false);
    }


    IEnumerator FollowPath()
    {
        /*foreach(Tile waypoint in path)*/
        for(int i=0;i<path.Count;i++)
        {
            Vector3 startPosition = transform.position;
            /*Vector3 endPosition = waypoint.transform.position;*/
            Vector3 endPosition = gridManager.GetPositionFormCoordinates(path[i].coordinates);
            float travelPercent = 0f;

            transform.LookAt(endPosition); //�����ϰ� �ִ� ������ �ٶ󺸵��� ó��

            while(travelPercent < 1f) { //0~1�� �¾�
                travelPercent += (Time.deltaTime * speed); //1������ ������
                transform.position = Vector3.Lerp(startPosition, endPosition, travelPercent); // ���� ���� -> ������, ����, ��� ������ ��ġ����.
                yield return new WaitForEndOfFrame(); //1������ ������, yield return
            }
        }

        FinishPath();
    }
}
