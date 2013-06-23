///////////////////////////////////////////////////////////
//  LineLayer.cs
//  Implementation of the Class LineLayer
//  Generated by Enterprise Architect
//  Created on:      08-四月-2011 13:45:31
//  Original author: Administrator
///////////////////////////////////////////////////////////




using DIST.DGP.DataExchange.VCT.ESRIData;
using DIST.DGP.DataExchange.VCT.FileData;
using System.Collections.Generic;
using System;
using ESRI.ArcGIS.Geodatabase;
namespace DIST.DGP.DataExchange.VCT.ESRIData {
	/// <summary>
	/// 线图层类
	/// </summary>
	public class LineLayer : FeatureLayer {

		public LineEntity m_LineEntity;

		public LineLayer(){

		}

		~LineLayer(){

		}

		public override void Dispose()
        {
            base.Dispose();
		}

        /// <summary>
        /// 创建
        /// </summary>
        public override bool Create(TableStructureNode tableStructureNode)
        {
            base.Create(tableStructureNode);

            return true;
        }

		/// <summary>
		/// 创建线实体
		/// </summary>
		/// <param name="entinyNode">VCT线实体节点</param>
		public override FeatureEntity CreateFeatureEntity(EntityNode entinyNode)
        {
            if (entinyNode is LineNode)
            {
                m_LineEntity = new LineEntity();
                m_LineEntity.SetFeatureKeyFieldName(m_strEntityFieldName, m_strSYDMFieldName);
                m_LineEntity.CreateFeature(this.Table, entinyNode);
               
                return m_LineEntity;
            }
            else
                return null;
		}

        /// <summary>
        /// 获取实体集合
        /// </summary>
        public override List<FeatureEntity> GetFeatureEntitys()
        {

            try
            {
                IFeatureClass pFeatureCls = this.Table as IFeatureClass;
                IFeatureCursor pCursor = pFeatureCls.Search(null, false);
                IFeature pFeature = pCursor.NextFeature();
                List<FeatureEntity> listFeatureEnty = new List<FeatureEntity>();//保存FeatureEntity
                while (pFeature != null)
                {
                    ///add by 曾平2011-9-7 添加裁切判断
                    ///裁切范围为空表示不进行裁切
                    if (m_CutGeometry != null)
                    {
                        if (!FeatureInCutRegion(pFeature.Shape))
                        {
                            pFeature = pCursor.NextFeature();
                            continue;
                        }
                    }
                    LineEntity pLineEntity = new LineEntity();
                    pLineEntity.Feature = pFeature;
                    pLineEntity.CutGeometry = m_CutGeometry;
                    pLineEntity.IsCut = m_bCut;
                    ///初始化相关数据
                    //pLineEntity.GetEntityNode();
                    pLineEntity.FeatureCode = this.FeatureCode;

                    int nEntityIDIndex = -1;
                    nEntityIDIndex = pFeature.Fields.FindField(m_strEntityFieldName);
                    if (nEntityIDIndex != -1)
                        pLineEntity.EntityID = Convert.ToInt32(pFeature.get_Value(nEntityIDIndex));

                    ///设置要素代码和标识码
                    pLineEntity.SetFeatureKeyFieldName(m_strEntityFieldName, m_strSYDMFieldName);

                    listFeatureEnty.Add(pLineEntity);
                    pFeature = pCursor.NextFeature();
                }
                m_FeatureEntys = listFeatureEnty;
                return listFeatureEnty;
            }
            catch (Exception ex)
            {
                LogAPI.WriteErrorLog(ex);
                return null;
            }
        }

	}//end LineLayer

}//end namespace ESRIData